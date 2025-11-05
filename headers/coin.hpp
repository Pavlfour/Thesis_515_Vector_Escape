#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Globals.hpp"


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
        bool coinUpdate(const sf::FloatRect& bitronBounds);

};