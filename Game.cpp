#include "Game.h"
#include "SplashState.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
namespace nn{
    
    Game::Game(unsigned int width, unsigned int height,
    std::string title){
        srand( time( NULL ) );
        m_data->window.create(sf::VideoMode(width, height), title,
        sf::Style::Close | sf::Style::Titlebar );
        this->m_data->machine.AddState(StateRef(new SplashState(this->m_data)));
        this->Run();
    }
    
    void Game::Run(){
        float newTime, frameTime, interpolation;
        float currentTime = this->clock.getElapsedTime().asSeconds(); //time elapsed since clock started
        float accumulator = 0.0f; //counts the total time

        while(this->m_data->window.isOpen()){
        
            this->m_data->machine.ProcessStateChanges(); //process the changes at start of every loop
            newTime = this->clock.getElapsedTime().asSeconds();
            //std::cout << 1.0/frameTime << std::endl; // print fps on console
            frameTime = newTime - currentTime; //time between two frames

            if(frameTime > 0.25f){ //restricting frame time if it goes too high
                frameTime = 0.25f;
            }
            currentTime = newTime;
            accumulator += frameTime;

            while(accumulator >= m_dt){
                this->m_data->machine.GetActiveState()->HandleInput();
                this->m_data->machine.GetActiveState()->Update(m_dt);
                accumulator -= m_dt;
            }
            interpolation = accumulator / m_dt;
            this->m_data->machine.GetActiveState()->Draw(interpolation);
        }
    }




}


























