#pragma once
#include <SFML/Graphics.hpp>
#include "mapManager.hpp"
#include "Sounds.hpp"
#include "Bitron.hpp"

class Bitron;

class mapManager;

class laser
{
    private:
        sf::Texture laserTexture;
        std::unique_ptr<sf::Sprite> laserSprite;      
        sf::Vector2f currentPos;
        bool direction;
        float speed,totalDistance;
        std::shared_ptr<Sounds> sound;

    public:
        laser(bool direction,sf::Vector2f currentPos,std::shared_ptr<Sounds> sound);
        void drawLaser(sf::RenderWindow* window);
        bool updateLaser(mapManager* currentMap,Bitron& bitron,Health& health);

};
