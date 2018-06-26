#ifndef LAND_H
#define LAND_H

// #include "State.h"

#include <vector>
#include "Game.h"
#include "SFML/Graphics.hpp"

namespace nn{

    class Land{
    public:
        Land(GameDataRef data);
        ~Land(){}
        void DrawLand();
        void MoveLand(float dt);
        const std::vector<sf::Sprite> &GetSprites() const;
    private:
        GameDataRef m_data;
        std::vector<sf::Sprite> m_landSprites;
    };

}


#endif