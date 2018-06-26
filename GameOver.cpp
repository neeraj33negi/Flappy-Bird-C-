#include "GameOver.h"
#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

namespace nn{

    GameOver::GameOver(GameDataRef data, int score) : m_data(data), m_score(score){

    }
    
    void GameOver::Init(){

        std::ifstream readFile;
        readFile.open( HIGHSCORE_FILE_PATH );
        if(readFile.is_open()){
            while( !readFile.eof() ){
                readFile >> m_highScore;
            }
        }
        readFile.close();

        std::ofstream writeFile( HIGHSCORE_FILE_PATH ) ;
        if( writeFile.is_open() ){
            if( m_score > m_highScore ){
                m_highScore = m_score;
            }
            writeFile << m_highScore;
        }
        writeFile.close();

        

        m_background.setTexture(this->m_data->assets.GetTexture("Game Over Background"));

        m_data->assets.LoadTexture("Game Over Title",
        GAMEOVER_TITLE_FILE_PATH);
        m_data->assets.LoadTexture("Game Over Body",
        GAMEOVER_BODY_FILE_PATH );
        m_data->assets.LoadTexture("Gold Medal",
        GOLD_MEDAL_FILE_PATH);
        m_data->assets.LoadTexture("Silver Medal",
        SILVER_MEDAL_FILE_PATH);
        m_data->assets.LoadTexture("Bronze Medal",
        BRONZE_MEDAL_FILE_PATH);
        m_data->assets.LoadTexture("Platinum Medal",
        PLATINUM_MEDAL_FILE_PATH);

        m_body.setTexture(m_data->assets.GetTexture( "Game Over Body" ));
        m_body.setPosition( SCREEN_WIDTH/2 - m_body.getGlobalBounds().width/2,
        SCREEN_HEIGHT/2 - m_body.getGlobalBounds().height /2 );

        m_title.setTexture(this->m_data->assets.GetTexture("Game Over Title"));
        m_title.setPosition(SCREEN_WIDTH/2.0 - m_title.getGlobalBounds().width/2.0,
        m_body.getPosition().y  - m_title.getLocalBounds().height * 1.2f);


        m_playButton.setTexture( m_data->assets.GetTexture( "Play Button" ));
        m_playButton.setPosition(SCREEN_WIDTH/2 - m_playButton.getGlobalBounds().width/2,
        m_body.getPosition().y + m_body.getGlobalBounds().height + m_playButton.getGlobalBounds().height * 0.2f);

        m_scoreText.setFont(m_data->assets.GetFont( "Flappy Font" ));
        m_scoreText.setString ( std::to_string( m_score ) );
        m_scoreText.setCharacterSize( 56 );
        m_scoreText.setColor( sf::Color::White );
        m_scoreText.setOrigin( m_scoreText.getGlobalBounds().width/2,
        m_scoreText.getGlobalBounds().height/2 );
        m_scoreText.setPosition(SCREEN_WIDTH/10 * 7.25f, SCREEN_HEIGHT/2.15f);

        m_highScoreText.setFont(m_data->assets.GetFont( "Flappy Font" ));
        m_highScoreText.setString ( std::to_string( m_highScore ) );
        m_highScoreText.setCharacterSize( 56 );
        m_highScoreText.setColor( sf::Color::White );
        m_highScoreText.setOrigin( m_highScoreText.getGlobalBounds().width/2,
        m_highScoreText.getGlobalBounds().height/2 );
        m_highScoreText.setPosition(SCREEN_WIDTH/10 * 7.25f, SCREEN_HEIGHT/1.78f);
         
        if (m_score > m_highScore){
            m_medal.setTexture( m_data->assets.GetTexture( "Platinum Medal" ) );
        }
        else{
            if ( m_score >= 50 ){
                m_medal.setTexture( m_data->assets.GetTexture( "Gold Medal" ) );
            }else if (m_score >= 25){
                m_medal.setTexture( m_data->assets.GetTexture( "Silver Medal" ) );
            }else{
                m_medal.setTexture( m_data->assets.GetTexture( "Bronze Medal" ) );
            }
        }

        m_medal.setPosition( SCREEN_WIDTH/2 - m_body.getGlobalBounds().width/2 * 0.725f ,
        SCREEN_HEIGHT/2 - m_body.getGlobalBounds().height /2 * 0.3f);

    }    

    void GameOver::HandleInput(){
        sf::Event event;

        while(this->m_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->m_data->window.close();
            }
            if(m_data->input.IsSpriteClicked( m_playButton, sf::Mouse::Left, m_data->window)){
                m_data->machine.AddState( StateRef ( new GameState(m_data))  );
            }
        }
    }

    void GameOver::Update(float dt){

        
    }

    void GameOver::Draw(float dt){
        this->m_data->window.clear();
        this->m_data->window.draw(m_background);
        this->m_data->window.draw(m_title);
        this->m_data->window.draw(m_body);
        this->m_data->window.draw(m_playButton);
        this->m_data->window.draw(m_scoreText);
        this->m_data->window.draw(m_highScoreText);
        this->m_data->window.draw(m_medal);
        this->m_data->window.display();
    }
}
