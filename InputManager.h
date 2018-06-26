
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <SFML/Graphics.hpp>
namespace nn{

    class InputManager{
    public:
        InputManager(){}
        ~InputManager(){}
        
        //Accepts sf::sprite object as argument and returns true if it was clicked
        bool IsSpriteClicked(sf::Sprite object,
        sf::Mouse::Button button, sf::RenderWindow &window);

        //returns integral vector position of the mouse pointer in game render window
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}

#endif