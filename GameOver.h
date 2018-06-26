#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "DEFINITIONS.h"
#include "SFML/Graphics.hpp"
#include "State.h"
#include "Game.h"


namespace nn{
    
    class GameOver: public State{
    
    public:
        GameOver(GameDataRef data, int score);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef m_data;
        sf::Sprite m_background;
        sf::Sprite m_title;
        sf::Sprite m_body;
        sf::Sprite m_playButton;
        sf::Text m_scoreText;
        sf::Text m_highScoreText;
        sf::Sprite m_medal;
        int m_score;
        int m_highScore;
    };
}

#endif