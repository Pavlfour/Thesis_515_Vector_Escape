#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "mapManager.hpp"
#include "Sounds.hpp"
#include "laser.hpp"
#include "Health.hpp"

class mapManager;
class laser;
class Health;

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

        std::shared_ptr<Sounds> sound;
        std::vector<std::unique_ptr<laser>> projectiles;

    public:
        Beamlok(sf::Vector2f startPos,sf::Vector2f endPos,float speed,std::shared_ptr<Sounds> sound);
        void updateBeamlok(Bitron& bitron,mapManager* currentMap,Health& health);
        void drawBeamlok(sf::RenderWindow& window);
        

};