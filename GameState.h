#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "DEFINITIONS.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Flash.h"
#include "HUD.h"

namespace nn{
    
    class GameState: public State{
    
    public:
        GameState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef m_data;
        sf::Sprite m_background;
        Pipe *m_pipe;
        Land *m_land;
        Bird *m_bird;
        Collision collision;
        sf::Clock m_clock;
        int m_gameState;
        Flash *m_flash;
        HUD *m_hud;
        int m_score;
        sf::SoundBuffer m_hitSoundBuffer;
        sf::SoundBuffer m_wingSoundBuffer;
        sf::SoundBuffer m_pointSoundBuffer;
        sf::Sound m_hitSound;
        sf::Sound m_wingSound;
        sf::Sound m_pointSound;
    };
}

#endif