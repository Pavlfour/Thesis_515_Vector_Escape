#pragma once
#include "Globals.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>

class Voltwing
{
    private:
        sf::Clock animationClock;
        sf::Texture voltwingTexture;
        std::unique_ptr<sf::Sprite> voltwingSprite;

        float frameTimer,speed,distance;
        short currentFrame,animationIterator;
        bool forward;

        sf::Vector2f voltwingPos;
        sf::Vector2f direction;

        unsigned char currentTargetIndex;
        std::vector<sf::Vector2f>pathPoints;


    public:
        Voltwing(std::vector<sf::Vector2f> points, float speed);

        bool updateVoltwing(const sf::FloatRect& bitronBounds,bool bitronIsDamaged);
        void drawVoltwing(sf::RenderWindow* window);

};