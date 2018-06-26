#ifndef GAME_H
#define GAME_H
#include <memory>
#include <string>
#include "StateMachine.h"
#include "InputManager.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>

namespace nn{

    struct GameData{
        sf::RenderWindow window;
        StateMachine machine;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef; //

    class Game{
    
    public:
    
        Game(unsigned int width, unsigned int height, 
        std::string title);
        ~Game(){}

    private:
        const float m_dt = 1.0f/60.0f; //time taken per frame,==>sets fps to 60
        sf::Clock clock; //to handle the frame rate
        GameDataRef m_data = std::make_shared<GameData>(); // a shared ptr to GameData

        void Run();


    };


}

#endif