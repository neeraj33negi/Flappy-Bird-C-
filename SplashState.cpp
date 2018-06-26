#include "SplashState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include <iostream>
#include "MainMenuState.h"

namespace nn{

    SplashState::SplashState(GameDataRef data) : m_data(data)
    {
        

    }
    void SplashState::Init(){
        m_data->assets.LoadTexture("Splash State Background",
        SPASH_SCREEN_BACKGROUND_FILE_PATH );
        m_background.setTexture(this->m_data->assets.GetTexture("Splash State Background"));
    }    

    void SplashState::HandleInput(){
        sf::Event event;

        while(this->m_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->m_data->window.close();
            }
        }
    }

    void SplashState::Update(float dt){

        if(this->m_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME ){
            //LOAD MAIN MENU
            m_data->machine.AddState(StateRef(new MainMenuState(m_data)), true );
             
        }
    }

    void SplashState::Draw(float dt){
        this->m_data->window.clear();
        this->m_data->window.draw(m_background);
        this->m_data->window.display();
    }
}