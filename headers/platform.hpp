#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Bitron;

class platform
{
    protected:
        // Common attributes
        float speed;
        sf::Vector2f platformPos;
        sf::Texture platformTexture;
        std::unique_ptr<sf::Sprite> platformSprite;

    public:
        platform();
        // Common methods
        void drawPlatform(sf::RenderWindow& window);
        virtual void platformUpdate(Bitron& bitron) = 0;

};