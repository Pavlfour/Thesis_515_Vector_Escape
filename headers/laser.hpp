#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Globals.hpp"
#include "mapManager.hpp"

class mapManager;

class laser
{
    private:
        sf::Texture laserTexture;
        std::unique_ptr<sf::Sprite> laserSprite;      
        sf::Vector2f currentPos;
        float speed,totalDistance;
        bool direction;

    public:
        laser(bool direction,sf::Vector2f currentPos);
        void drawLaser(sf::RenderWindow* window);
        unsigned char updateLaser(mapManager* currentMap,bool bitronIsDamaged,const sf::FloatRect& bitronBounds);
};
