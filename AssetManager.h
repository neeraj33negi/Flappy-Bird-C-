#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

namespace nn{
    class AssetManager{
    public:
        AssetManager(){}
        ~AssetManager(){}
        
        void LoadTexture(std::string name, std::string fileName); 
        sf::Texture &GetTexture(std::string name); //takes name of a texture and returns a reference to it

        void LoadFont(std::string name, std::string fileName); 
        sf::Font &GetFont(std::string name);
    
    private:
        std::map<std::string, sf::Texture> m_textures;
        std::map<std::string, sf::Font> m_fonts;

    };
}

#endif