#include "MainMenuState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace nn{

    MainMenuState::MainMenuState(GameDataRef data) : m_data(data)
    {
        

    }
    void MainMenuState::Init(){
        m_data->assets.LoadTexture("Main Menu State Background",
        MAIN_MENU_BACKGROUND_FILE_PATH );
        m_background.setTexture(this->m_data->assets.GetTexture
        ("Main Menu State Background"));

        m_data->assets.LoadTexture("Game Title",
        GAME_TITLE_FILE_PATH );
        m_title.setTexture(this->m_data->assets.GetTexture("Game Title"));
        m_title.setPosition( SCREEN_WIDTH/2.0 - (m_title.getGlobalBounds().width/2.0),
        m_title.getLocalBounds().height/2.0 );

        m_data->assets.LoadTexture("Play Button",
        PLAY_BUTTON_FILE_PATH );
        m_playButton.setTexture(this->m_data->assets.GetTexture("Play Button"));
        m_playButton.setPosition(SCREEN_WIDTH/2.0 - m_playButton.getGlobalBounds().width /2.0,
        SCREEN_HEIGHT/2.0 - m_playButton.getGlobalBounds().height / 2.0);
    }    

    void MainMenuState::HandleInput(){
        sf::Event event;

        while(this->m_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->m_data->window.close();
            }
            if(this->m_data->input.IsSpriteClicked( m_playButton,
            sf::Mouse::Left,this->m_data->window)){
                this->m_data->machine.AddState(StateRef(new GameState(m_data)),
                true);
            }
        }
    }

    void MainMenuState::Update(float dt){

        
    }

    void MainMenuState::Draw(float dt){
        this->m_data->window.clear();
        this->m_data->window.draw(m_background);
        this->m_data->window.draw(m_title);
        this->m_data->window.draw(m_playButton);
        this->m_data->window.display();
    }
}