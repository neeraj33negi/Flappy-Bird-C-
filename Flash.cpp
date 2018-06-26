#include "Flash.h"
#include "DEFINITIONS.h"

namespace nn{

    Flash::Flash(GameDataRef data): m_data(data){

        m_shape = sf::RectangleShape( sf::Vector2f( m_data->window.getSize() ) );
        m_shape.setFillColor( sf::Color(255, 255, 255, 0) );
        m_flashOn = true;

    }

    void Flash::Draw(){

        m_data->window.draw(m_shape);

    }

    void Flash::Show(float dt){

        if ( m_flashOn ){

            int alpha = (int)m_shape.getFillColor().a + ( FLASH_SPEED * dt );
            if ( alpha >= 255.0f ){
                alpha = 255.0f;
                m_flashOn = false;
            }

            m_shape.setFillColor( sf::Color( 255, 255, 255, alpha ) );

        }else{

            int alpha = (int)m_shape.getFillColor().a - ( FLASH_SPEED * dt );
            if ( alpha <= 0.0f ){
                alpha = 0.0f;
                m_flashOn = false;
            }

            m_shape.setFillColor( sf::Color( 255, 255, 255, alpha ) );

        }

    }

}