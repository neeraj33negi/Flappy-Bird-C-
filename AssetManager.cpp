#include "AssetManager.h"

namespace nn{
    void AssetManager::LoadTexture(std::string name, std::string fileName){
        sf::Texture tex;
        if(!tex.loadFromFile(fileName)){
            //Handle exception -> file coudn't be loaded
        }else{
            this->m_textures[name] = tex;
        }
    }

    sf::Texture &AssetManager::GetTexture(std::string name){
        return this->m_textures.at(name);
    }


    void AssetManager::LoadFont(std::string name, std::string fileName){
        sf::Font fnt;
        if(!fnt.loadFromFile(fileName)){
            //Handle exception -> file coudn't be loaded
        }else{
            this->m_fonts[name] = fnt;
        }
    }

    sf::Font &AssetManager::GetFont(std::string name){
        return this->m_fonts.at(name);
    }
}