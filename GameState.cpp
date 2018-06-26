#include "GameState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include "GameOver.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pipe.h"
#include "GameOver.h"

namespace nn{

    GameState::GameState(GameDataRef data) : m_data(data)
    {
        m_gameState =  GameStates::eReady;
        m_score = 0;
       // m_hud->UpdateScore(m_score);
    }

    void GameState::Init(){
        m_data->assets.LoadTexture("Game State Background",
        GAME_BACKGROUND_FILE_PATH);
        m_data->assets.LoadTexture("Pipe Up",
        PIPE_UP_FILE_PATH);
        m_data->assets.LoadTexture("Land",
        LAND_FILE_PATH);
        m_data->assets.LoadTexture("Pipe Down",
        PIPE_DOWN_FILE_PATH);
        m_data->assets.LoadTexture("Bird Frame1", 
        BIRD_FRAME1_FILE_PATH);
        m_data->assets.LoadTexture("Bird Frame2", 
        BIRD_FRAME2_FILE_PATH);
        m_data->assets.LoadTexture("Bird Frame3", 
        BIRD_FRAME3_FILE_PATH);
        m_data->assets.LoadTexture("Bird Frame4", 
        BIRD_FRAME4_FILE_PATH);
        m_data->assets.LoadTexture("Scoring Pipe",
        SCORING_PIPE_FILE_PATH);
        m_data->assets.LoadTexture("Game Over Background",
        GAMEOVER_BACKGROUND_FILE_PATH);


        m_data->assets.LoadFont( "Flappy Font", FLAPPY_FONT_FILE_PATH);

        m_background.setTexture(
        this->m_data->assets.GetTexture("Game State Background") );
        
        m_land = new Land(m_data);
        m_pipe = new Pipe(m_data);
        m_bird = new Bird(m_data);
        m_flash = new Flash(m_data);
        m_hud = new HUD(m_data);
        
        if( !m_hitSoundBuffer.loadFromFile(HIT_SOUND_FILE_PATH) ){
            //Handle error
        }
        if( !m_wingSoundBuffer.loadFromFile(WING_SOUND_FILE_PATH) ){
            //Handle error
        }
        if( !m_pointSoundBuffer.loadFromFile(POINT_SOUND_FILE_PATH) ){
            //Handle error
        }
        m_hitSound.setBuffer( m_hitSoundBuffer );
        m_wingSound.setBuffer( m_wingSoundBuffer );
        m_pointSound.setBuffer( m_pointSoundBuffer );



       
        
    }    

    void GameState::HandleInput(){
        sf::Event event;

        while(this->m_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->m_data->window.close();
            }
            if(m_data->input.IsSpriteClicked(m_background, sf::Mouse::Left, m_data->window)){

                if (m_gameState != GameStates::eGameOver){
                    m_gameState = GameStates::ePlaying;
                    m_bird->Tap();
                    m_wingSound.play();
                }
            }
        }
    }

    void GameState::Update(float dt){
        if (m_gameState != GameStates::eGameOver){
            m_bird->Animate(dt);
            m_land->MoveLand(dt);
        }

        if (m_gameState == GameStates::ePlaying){
            m_pipe->MovePipes(dt);
            if(m_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY){
                m_pipe->RandomizePipeOffset();
                m_pipe->SpawnInvisiblePipe();
                m_pipe->SpawnBottomPipe();
                m_pipe->SpawnTopPipe();
                m_pipe->SpawnScoringPipe();
                m_clock.restart();
            }
            m_bird->Update(dt);
            std::vector<sf::Sprite> landSprites = m_land->GetSprites();
            std::vector<sf::Sprite> pipeSprites = m_pipe->GetSprites();
            std::vector<sf::Sprite> &scoringSprites = m_pipe->GetScoringSprites();

            for (unsigned short int i = 0; i < landSprites.size() ; ++i){
                if( collision.CheckSpriteCollision( landSprites.at(i), 1.0f, m_bird->GetSprite(), 0.75f ) ){
                    m_gameState = GameStates::eGameOver;
                    m_clock.restart();
                    m_hitSound.play();
                }
            }

            for (unsigned short int i = 0; i < pipeSprites.size(); ++i){
                if ( collision.CheckSpriteCollision ( pipeSprites.at(i), 0.625f, m_bird->GetSprite(), 1.0f ) ){
                    m_gameState = GameStates::eGameOver;
                    m_clock.restart();
                    m_hitSound.play();
                }
            }

            for (unsigned short int i = 0; i < scoringSprites.size(); ++i){
                if ( collision.CheckSpriteCollision ( scoringSprites.at(i), 0.625f, m_bird->GetSprite(), 1.0f ) ){
                    ++m_score;
                    m_hud->UpdateScore(m_score);
                    //std::cout << m_score << std::endl;
                    //Erase the sprite after collision, otherwise score will keep increasing for all the frames where bird and sprite is colliding
                    //So same sprite wouldn't be counter more than once after the collision
                    scoringSprites.erase(scoringSprites.begin() + i);
                    m_pointSound.play();
                }
            }
        }   
        if(m_gameState == GameStates::eGameOver) {
            m_flash->Show(dt);
            if (m_clock.getElapsedTime().asSeconds() >= TIME_BEFORE_GAMEOVER_APPEARS){
                m_data->machine.AddState( StateRef (new GameOver(m_data, m_score)), true);
            }
        }
    }

    void GameState::Draw(float dt){
        this->m_data->window.clear();
        this->m_data->window.draw(m_background);
        this->m_pipe->DrawPipes();   
        this->m_land->DrawLand(); 
        this->m_bird->Draw();
        this->m_flash->Draw();
        this->m_hud->Draw();
        this->m_data->window.display();
    }
}


















