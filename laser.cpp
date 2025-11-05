#include "headers/laser.hpp"

laser::laser(bool direction,sf::Vector2f currentPos):
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


unsigned char laser::updateLaser(mapManager* currentMap,bool bitronIsDamaged,const sf::FloatRect& bitronBounds)
{
    // Τσεκάρουμε για τυχόν σύγκρουση μεταξύ Bitron και Laser
    sf::FloatRect laserBounds =sf::FloatRect({currentPos.x, currentPos.y}, {10.f, 5.f});

    // Η θέση στο X
    short x = (direction) ? floor((currentPos.x + 10.f) / static_cast<float>(cellSize)) : floor((currentPos.x) / static_cast<float>(cellSize));
    // Η θέση στο Y
    short y = floor(currentPos.y / static_cast<float>(cellSize));

    if(currentMap->projectileCollicion(x,y) && (!bitronBounds.findIntersection(laserBounds) || bitronIsDamaged) &&
        (abs(totalDistance) < static_cast<float>(7*cellSize - 32) ))
    {
        currentPos.x += speed;
        totalDistance += speed;
        return 1;
    }
    else if(bitronBounds.findIntersection(laserBounds) && !bitronIsDamaged)
    {
        return 2;
    }

    return 3;
}

void laser::drawLaser(sf::RenderWindow* window)
{
    laserSprite->setPosition({currentPos});
    window->draw(*laserSprite);
}
