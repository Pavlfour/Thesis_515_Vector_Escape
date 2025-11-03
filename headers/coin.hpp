#pragma once
#include <SFML/Graphics.hpp>
#include "mapManager.hpp"

class Bitron;

class coin
{
    private:
        sf::Clock animationClock;
        sf::Texture coinTexture;
        std::unique_ptr<sf::Sprite> coinSprite;

        float x,y,frameTimer;
        short currentFrame,animationIterator;

    public:
        coin(float x, float y);

        void drawCoin(sf::RenderWindow* window);
        bool coinUpdate(Bitron& bitron);

};