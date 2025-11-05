#include "headers/platform.hpp"

platform::platform()
{

    if(!platformTexture.loadFromFile("assets/sprites/blue.png"))
    {
        throw std::runtime_error("Failed to load blue.png");
    }

    platformSprite = std::make_unique<sf::Sprite>(platformTexture);
}

void platform::drawPlatform(sf::RenderWindow* window)
{
    platformSprite->setPosition(platformPos);
    window->draw(*platformSprite);
}