#include "headers/Health.hpp"

Health::Health():
totalHealthCount(3)
{

    if(!healthTexture.loadFromFile("assets/sprites/Health.png"))
    {
        throw std::runtime_error("Failed to load Health.png");
    }
    healthSprite = std::make_unique<sf::Sprite>(healthTexture);
}

void Health::drawHealth(sf::RenderWindow* window)
{

    for(short i=0;i<totalHealthCount;i++)
    {
        healthSprite->setPosition({i*32.f + x,y});
        window->draw(*healthSprite);
    }

}

void Health::updateHealth(sf::View& view)
{
    this->x = view.getCenter().x - view.getSize().x/2.f;
    this->y = view.getCenter().y - view.getSize().y/2.f;
}

void Health::damageTaken()
{
    totalHealthCount--;
}

void Health::addHealth()
{
    totalHealthCount++;
}