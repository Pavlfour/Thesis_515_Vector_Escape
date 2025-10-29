#include "headers/Game.hpp"

Game::Game():
sound(std::make_shared<Sounds>()),
bitron(sound),
map(sound),
mainMenu(true),
isTerminated(false),
isFinished(false),
m_elapsed(0.f)
{
    m_clock.restart();
    srand(time(nullptr));

    view = sf::View({0,0},{viewSize.x,viewSize.y});

    // Window module
    window.create(sf::VideoMode({windowWidth,windowHeight}),"Vector Escape",sf::Style::Titlebar | sf::Style::Close);

    // Icon
    if(!icon.loadFromFile("assets/sprites/icon.png"))
    {
        throw std::runtime_error("Failed to load icon.png");
    }
    window.setIcon({icon.getSize().x, icon.getSize().y}, icon.getPixelsPtr());

    // Main menu background
    if(!mainMenuTexture.loadFromFile("assets/sprites/menu.png"))
    {
        throw std::runtime_error("Failed to load menu.png");
    }
    mainMenuSprite = std::make_unique<sf::Sprite>(mainMenuTexture);

    text.setMainMenuText();

}

bool Game::isRunning()
{

    while (const std::optional event = window.pollEvent())
    {
            
        if (event->is<sf::Event::Closed>())
        {
            window.close();
            return false;
        }
    }

    while (m_elapsed >= timestep)
    {
        update();
        m_elapsed -= timestep;
    }

    draw();
    
    m_elapsed += m_clock.restart().asSeconds();

    // Prevent "spiral of death"
    if(m_elapsed > 0.25)
        m_elapsed = 0.25;

    return true;

}

void Game::update()
{

    // Loser
    if(isTerminated)
    {
        return;
    }
    // Main Menu
    else if(mainMenu)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
        {
            mainMenu = false;
            sound->playBackgroundMusic();
        }

        return;
    }
    // Game Over
    else if(health.gameOver())
    {
        text.setGameOverText(view.getCenter().x - 319.f,view.getCenter().y - 128.f);
        sound->stopBackgroundMusic();
        isTerminated = true;
        sound->playGameOver();
        return;
    }
    // Winner
    else if(map.getCurrentMapIndex() == 9 && !isFinished)
    {
        text.setWinnerText(view.getCenter().x - 240.f,view.getCenter().y - 128.f);
        sound->stopBackgroundMusic();
        isFinished = true;
        sound->playWin();
        return;
    }
    



    // Update first bitron for positioning the view correctly 
    bitron.updateBitron(map,health);
    map.updateCamera(window,view,bitron.getX(),bitron.getY());
    // Update the rest componets
    map.updatePlatforms(bitron);
    map.updateCoins(bitron,health);
    map.updateVoltwings(bitron,health);
    map.updateCoinsText(view);
    map.updateBeamloks(bitron,health);
    health.updateHealth(view);

}

void Game::draw()
{

    window.clear();

    if(!mainMenu)
    {
        
        map.drawMap(window);
        health.drawHealth(window);
        bitron.drawBitron(window);
        if(isTerminated || isFinished)
        {
            window.draw(text.getText());
        }

    }
    else
    {
        window.draw(*mainMenuSprite);
        window.draw(text.getText());
    }

    window.display();
}