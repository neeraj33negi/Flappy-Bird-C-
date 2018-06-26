#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINITIONS.h"

namespace nn{

    class Pipe{
    public:
        Pipe(GameDataRef data);
        ~Pipe(){}

        void DrawPipes();
        void SpawnBottomPipe();
        void SpawnScoringPipe();
        void SpawnTopPipe();
        void SpawnInvisiblePipe();
        void MovePipes(float dt);
        void RandomizePipeOffset();

        const std::vector<sf::Sprite> &GetSprites();
        std::vector<sf::Sprite> &GetScoringSprites();
    
    private:

        GameDataRef m_data;
        std::vector<sf::Sprite> m_pipeSprites;
        std::vector<sf::Sprite> m_scoringPipes;
        int m_landHeight;
        int m_pipeSpawnYOffset;


    };
}

#endif