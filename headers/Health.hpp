#pragma once
#include "Globals.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Health
{
    private:
        sf::Texture healthTexture;
        std::unique_ptr<sf::Sprite> healthSprite;
        unsigned short totalHealthCount;
        float x,y;

    public:
        Health();
        void drawHealth(sf::RenderWindow* window);
        void updateHealth(sf::View& view);
        void damageTaken();

        bool gameOver()const{return totalHealthCount==0;}
        void addHealth();
};