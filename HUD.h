#ifndef  HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

namespace nn{

    class HUD{
    
    public:
        HUD(GameDataRef data);
        ~HUD();
        void Draw();
        void UpdateScore(int score);

    private:
        GameDataRef m_data;
        sf::Text m_scoreText;

    };

}



#endif // ! HUD_