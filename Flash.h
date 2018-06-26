#ifndef FLASH_H
#define FLASH_H

#include <SFML/Graphics.hpp>
#include "Game.h"

namespace nn{

    class Flash{

    public:
        Flash(GameDataRef data);
        void Show(float dt);
        void Draw();

    private:
        sf::RectangleShape m_shape;
        bool m_flashOn;
        GameDataRef m_data;

    };

}

#endif