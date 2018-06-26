#include "Land.h"
#include "DEFINITIONS.h"

namespace nn{

    Land::Land(GameDataRef data): m_data(data){

        sf::Sprite landSprite1(m_data->assets.GetTexture("Land"));
        sf::Sprite landSprite2(m_data->assets.GetTexture("Land"));

        landSprite1.setPosition(0.0f, 
        m_data->window.getSize().y - landSprite1.getGlobalBounds().height);

        landSprite2.setPosition(landSprite2.getGlobalBounds().width, 
        m_data->window.getSize().y - landSprite2.getGlobalBounds().height);

        m_landSprites.push_back(landSprite1);
        m_landSprites.push_back(landSprite2);

    }

    void Land::DrawLand(){

        for (unsigned short int i = 0; i < m_landSprites.size(); ++i ){

            m_data->window.draw(m_landSprites.at(i));
        }

    }

    void Land::MoveLand(float dt){

        for (unsigned short int i = 0; i < m_landSprites.size(); ++i ){
            float movement = LAND_MOVEMENET_SPEED * dt;
            m_landSprites.at(i).move(-movement, 0.0f);
            if (m_landSprites.at(i).getPosition().x <
            -m_landSprites.at(i).getGlobalBounds().width){
            
                m_landSprites.at(i).setPosition(m_data->window.getSize().x,
                m_landSprites.at(i).getPosition().y );
            }

        }

    }

    const std::vector<sf::Sprite> &Land::GetSprites() const{
        return m_landSprites;
    }



}