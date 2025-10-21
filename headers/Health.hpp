#pragma once
#include <SFML/Graphics.hpp>

class Health
{
    private:
        sf::Texture healthTexture;
        std::unique_ptr<sf::Sprite> healthSprite;
        unsigned short totalHealthCount;
        float x,y;

    public:
        Health();
        void drawHealth(sf::RenderWindow& window);
        void updateHealth(sf::View& view);
        void damageTaken();

        bool gameOver()const{return totalHealthCount==0;}
        void addHealth();
};