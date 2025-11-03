#include "headers/laser.hpp"

laser::laser(bool direction,sf::Vector2f currentPos,std::shared_ptr<Sounds> sound):
sound(sound),
totalDistance(0.f)
{
    this->direction = direction;
    this->currentPos = currentPos;

    if(!laserTexture.loadFromFile("assets/sprites/laser.png"))
    {
        throw std::runtime_error("Failed to load lase.png");
    }

    laserSprite = std::make_unique<sf::Sprite>(laserTexture);

    direction?speed=5.5f:speed=-5.5f;
    if(!direction)
    {
        laserSprite->setScale({-1.f,1.f});
        laserSprite->setOrigin({10.f,0.f});
    }
}


bool laser::updateLaser(mapManager* currentMap,Bitron& bitron,Health& health)
{

    // Τσεκάρουμε για τυχόν σύγκρουση μεταξύ Bitron και Laser
    sf::FloatRect laserBounds =sf::FloatRect({currentPos.x, currentPos.y}, {10.f, 5.f});
    sf::FloatRect bitronBounds({bitron.getX()+2.f, bitron.getY()}, {30.0f, 32.0f});

    // Η θέση στο X
    short x = (direction) ? floor((currentPos.x + 10.f) / 64.f) : floor((currentPos.x) / 64.f);
    // Η θέση στο Y
    short y = floor(currentPos.y / 64.f);

    if(currentMap->projectileCollicion(x,y) && (!bitronBounds.findIntersection(laserBounds) || bitron.getDamageStatus()) &&
        (abs(totalDistance) < 416.f ))
    {
        currentPos.x += speed;
        totalDistance += speed;
        return true;
    }
    else if(bitronBounds.findIntersection(laserBounds) && !bitron.getDamageStatus())
    {
        sound->playDie();
        health.damageTaken();
        bitron.bitronIsDamaged();
        return false;
    }
    
    return false;
    
}

void laser::drawLaser(sf::RenderWindow* window)
{
    laserSprite->setPosition({currentPos});
    window->draw(*laserSprite);
}
