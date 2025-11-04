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

bool Window::windowIsDone()
{
        while (const std::optional event = window.pollEvent())
        {
                
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                return true;
            }
        }
        return false;
}

void Window::drawText(unsigned short currentMapIndex)
{
    if (currentMapIndex < 3 || !isRunning)
    {
        window.draw(text->getStateText());
    }
    window.draw(text->getCoinText());
}

void Window::beginDraw()
{
    window.clear();
}

void Window::backgroundDraw()
{
    window.draw(*backgroundSprite);
}

void Window::mainMenuDraw()
{
    window.draw(*mainMenuSprite);
}

void Window::endDraw()
{
    window.display();
}

void Window::firstMapText()
{
    text->setFirstMapText();
}

void Window::updateCamera(float x,float y,unsigned short mapPixelWidth,unsigned short mapPixelHeight)
{

        centerX = x + 16.0f;
        centerY = y + 16.0f;

        centerX = std::clamp(centerX, viewSize.x/2.f, mapPixelWidth - viewSize.x/2.f);
        centerY = std::clamp(centerY, viewSize.y/2.f, mapPixelHeight - viewSize.y/2.f);

        view.setCenter({centerX, centerY});
        window.setView(view);

        // Background update
        backgroundSprite->setPosition({view.getCenter().x - 512.f -32.f,view.getCenter().y - 464.f});
        text->updateCoinPosition(centerX - view.getSize().x/2.f + 4.f,centerY - view.getSize().y/2.f + 32.f);

}

void Window::gameOver()
{
    text->setGameOverText(view.getCenter().x - 205.f,view.getCenter().y - 128.f);
    isRunning = false;
}

void Window::winner()
{
    text->setWinnerText(view.getCenter().x - 130.f,view.getCenter().y - 128.f);
    isRunning = false;
}