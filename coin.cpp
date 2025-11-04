#include "headers/coin.hpp"

coin::coin(float x,float y):
frameTimer(0.0f),
currentFrame(0),
animationIterator(0)
{
    this->x=x;
    this->y=y;
    
    if(!coinTexture.loadFromFile("assets/sprites/coin.png"))
    {
        throw std::runtime_error("Failed to load coin.png");
    }
    coinSprite = std::make_unique<sf::Sprite>(coinTexture);
}

bool coin::coinUpdate(const sf::FloatRect& bitronBounds)
{
    /////////////////////////////////////// Animation part ///////////////////////////////////////
    while(animationIterator >= 5)
    {
        animationIterator -= 5;
        currentFrame = (1+currentFrame)%10;
    }
    animationIterator++;
    coinSprite->setTextureRect(sf::IntRect({currentFrame*18,0},{18,18}));
    //////////////////////////////////////////////////////////////////////////////////////////////

    // Αλλάξαμε το πλαίσιο ώστε να είναι πιο ακριβής η επαφή με τον παίκτη
    sf::FloatRect coinBounds({x + 7.f, y + 5.f}, {4.0f, 8.0f});

    if (bitronBounds.findIntersection(coinBounds))
        return true;
    else
        return false;

}

void coin::drawCoin(sf::RenderWindow* window)
{
    coinSprite->setPosition({x,y});
    window->draw(*coinSprite);

}