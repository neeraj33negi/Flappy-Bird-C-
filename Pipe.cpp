#include "Pipe.h"

namespace nn{

    Pipe::Pipe(GameDataRef data) : m_data(data)
    {
        m_landHeight = m_data->assets.GetTexture("Land").getSize().y;
        m_pipeSpawnYOffset = 0;
    }

    void Pipe::DrawPipes(){
        for(unsigned short int i = 0; i < m_pipeSprites.size(); ++i ){
            m_data->window.draw(m_pipeSprites.at(i));
        }
    }

    void Pipe::SpawnBottomPipe(){
        //Pipe spawning at bottom faces upwards
        sf::Sprite bottomPipeSprite(m_data->assets.GetTexture("Pipe Up"));
        
        bottomPipeSprite.setPosition(m_data->window.getSize().x,
        m_data->window.getSize().y - bottomPipeSprite.getGlobalBounds().height - m_pipeSpawnYOffset);

        m_pipeSprites.push_back(bottomPipeSprite);
    }

    void Pipe::SpawnTopPipe(){
        sf::Sprite topPipeSprite(m_data->assets.GetTexture("Pipe Down"));
        
        topPipeSprite.setPosition(m_data->window.getSize().x,
        - m_pipeSpawnYOffset);
        
        m_pipeSprites.push_back(topPipeSprite);
    }

    void Pipe::SpawnInvisiblePipe(){
        sf::Sprite invisiblePipeSprite(m_data->assets.GetTexture("Pipe Up"));
        
        invisiblePipeSprite.setPosition(m_data->window.getSize().x,
        m_data->window.getSize().y - invisiblePipeSprite.getGlobalBounds().height);
        
        invisiblePipeSprite.setColor(sf::Color( 0, 0, 0, 0 ));
        
        m_pipeSprites.push_back(invisiblePipeSprite);
    }

    void Pipe::MovePipes(float dt){
        for(unsigned short int i = 0; i < m_pipeSprites.size(); ++i ){
            
            if (m_pipeSprites.at(i).getPosition().x < 0 -
            m_pipeSprites.at(i).getGlobalBounds().width){

                m_pipeSprites.erase(m_pipeSprites.begin() + i);
             }else{
                float movement = PIPE_MOVEMENT_SPEED * dt;
                    m_pipeSprites.at(i).move( -movement, 0.0f );
            }
        }
        for(unsigned short int i = 0; i < m_scoringPipes.size(); ++i ){

            float movement = PIPE_MOVEMENT_SPEED * dt;
            m_scoringPipes.at(i).move( -movement, 0.0f );
            
        }

    }

    void Pipe::RandomizePipeOffset(){
        m_pipeSpawnYOffset = rand() % (m_landHeight + 1);
    }

    const std::vector<sf::Sprite> &Pipe::GetSprites(){
        return m_pipeSprites;
    }

    void Pipe::SpawnScoringPipe(){
        sf::Sprite scoringPipe( m_data->assets.GetTexture( "Scoring Pipe" ) );
        scoringPipe.setPosition(m_data->window.getSize().x + scoringPipe.getGlobalBounds().width, 0);
        m_scoringPipes.push_back(scoringPipe);
    }

    std::vector<sf::Sprite> &Pipe::GetScoringSprites(){
        return m_scoringPipes;
    }
}






















