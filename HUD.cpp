#include "HUD.h"
#include <iostream>
#include <string>

namespace nn{

    HUD::HUD(GameDataRef data): m_data(data)
    {
        m_scoreText.setFont( m_data->assets.GetFont( "Flappy Font" ) );
        
        m_scoreText.setString( "0" );
        
        m_scoreText.setCharacterSize( 128 );
        
        m_scoreText.setColor( sf::Color::White );
        
        m_scoreText.setOrigin( m_scoreText.getGlobalBounds().width/2,
        m_scoreText.getGlobalBounds().height/2 );

        m_scoreText.setPosition( m_data->window.getSize().x/2,
        m_data->window.getSize().y/5 );

    }

    void HUD::Draw(){

        m_data->window.draw(m_scoreText);

    }

    void HUD::UpdateScore(int score){

        m_scoreText.setString( std::to_string(score) );

    }

}