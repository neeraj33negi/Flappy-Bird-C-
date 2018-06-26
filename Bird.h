#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>


namespace nn{
    
    class Bird{
    public:
        Bird(GameDataRef data);
        ~Bird(){}
        void Draw();
        void Animate(float dt);
        void Update(float dt);
        void Tap();
        const sf::Sprite &GetSprite() const;
    
    private:
        GameDataRef m_data;
        sf::Sprite m_birdSprite;
        std::vector <sf::Texture> m_birdTexture;
        sf::Clock m_clock;
        unsigned int m_animationIterator;
        sf::Clock m_movementClock;
        int m_birdState;
        float m_rotationAngle;
    };
}


#endif