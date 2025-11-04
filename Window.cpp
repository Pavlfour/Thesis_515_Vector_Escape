#include "headers/Window.hpp"

Window::Window():
isRunning(true),
text(std::make_unique<windowText>())
{
    view = sf::View({0,0},{viewSize.x,viewSize.y});

    // Window module
    window.create(sf::VideoMode({windowWidth,windowHeight}),"Vector Escape",sf::Style::Titlebar | sf::Style::Close);

    // Main menu background
    if(!mainMenuTexture.loadFromFile("assets/sprites/menu.png") || !backgroundTexture.loadFromFile("assets/sprites/background.png")
        || !icon.loadFromFile("assets/sprites/icon.png"))
    {
        throw std::runtime_error("Failed to load textures");
    }

    window.setIcon({icon.getSize().x, icon.getSize().y}, icon.getPixelsPtr());
    mainMenuSprite = std::make_unique<sf::Sprite>(mainMenuTexture);
    backgroundSprite = std::make_unique<sf::Sprite>(backgroundTexture);
}
