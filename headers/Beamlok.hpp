#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Globals.hpp"
#include "mapManager.hpp"
#include "laser.hpp"

class mapManager;
class laser;

class Beamlok
{
    private:
        short currentFrame,animationIterator;
        float speed,distance;
        bool forward,attackMode,fire;


        sf::Texture beamlokTexture;
        std::unique_ptr<sf::Sprite> beamlokSprite;

        sf::Vector2f direction;
        sf::Vector2f startPos;
        sf::Vector2f endPos;
        sf::Vector2f target;
        sf::Vector2f beamlokPos;

        std::vector<std::unique_ptr<laser>> projectiles;

    public:

        Beamlok(sf::Vector2f startPos,sf::Vector2f endPos,float speed);

        unsigned char updateBeamlok(sf::FloatRect bitronBounds,bool bitronIsDamaged,mapManager* currentMap);
        void drawBeamlok(sf::RenderWindow* window);
        unsigned char updateAnimation();
        

};