#include "Bird.h"
#include "State.h"
#include "DEFINITIONS.h"

namespace nn {

    Bird::Bird( GameDataRef data ) : m_data( data )
    {
        m_animationIterator = 0;

        m_birdTexture.push_back(m_data->assets.GetTexture("Bird Frame1"));
        m_birdTexture.push_back(m_data->assets.GetTexture("Bird Frame2"));
        m_birdTexture.push_back(m_data->assets.GetTexture("Bird Frame3"));
        m_birdTexture.push_back(m_data->assets.GetTexture("Bird Frame4"));

        m_birdSprite.setTexture(m_birdTexture.at(0));
        m_birdSprite.setPosition(SCREEN_WIDTH/4 - m_birdSprite.getGlobalBounds().width/2,
        SCREEN_HEIGHT/2 - m_birdSprite.getGlobalBounds().height/2);

        m_birdState = 1;
        sf::Vector2f birdOrigin = sf::Vector2f(
            m_birdSprite.getGlobalBounds().width/2.0f,
            m_birdSprite.getGlobalBounds().height/2.0f
        );
        m_birdSprite.setOrigin(birdOrigin);
        m_rotationAngle = 0;
    }

    void Bird::Draw(){
        m_data->window.draw( m_birdSprite );
    }

    void Bird::Animate(float dt){

        if (m_clock.getElapsedTime().asSeconds() >
        BIRD_ANIMATION_DURATION / m_birdTexture.size()){
            
            if(m_animationIterator < m_birdTexture.size() - 1){
                ++m_animationIterator;
            }else{
                m_animationIterator = 0;
            }

            m_birdSprite.setTexture( m_birdTexture.at( m_animationIterator ) );
            m_clock.restart();
        }
    }

    void Bird::Update(float dt){
        if  (m_birdState == BIRD_STATE_FALLING ){
            m_birdSprite.move(0, GRAVITY*dt);
            m_rotationAngle += BIRD_ROTATION_SPEED * dt;

            if ( m_rotationAngle > 25.0f ) m_rotationAngle = 25.0f;
            m_birdSprite.setRotation(m_rotationAngle);
        }
        if ( m_birdState == BIRD_STATE_FLYING ){
            m_birdSprite.move(0, -BIRD_FLYING_SPEED*dt);
            m_rotationAngle -= BIRD_ROTATION_SPEED * dt;

            if ( m_rotationAngle < -25.0f ) m_rotationAngle = -25.0f;
            m_birdSprite.setRotation(m_rotationAngle);
        }
        if ( m_movementClock.getElapsedTime().asSeconds() > BIRD_FLYING_DURATION){
            m_birdState = BIRD_STATE_FALLING;
            m_movementClock.restart();
        }


    }

    void Bird::Tap(){
        
        m_movementClock.restart();
        m_birdState = BIRD_STATE_FLYING;
        
    }

    const sf::Sprite &Bird::GetSprite() const{
        return m_birdSprite;
    }

}
















































