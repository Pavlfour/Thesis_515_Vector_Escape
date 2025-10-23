#include "headers/Game.hpp"

Game::Game():
sound(std::make_shared<Sounds>()),
bitron(sound),
map(sound),
mainMenu(true),
count(0),
currentFPS(0.),
m_elapsed(0.f),
checkOnce(false),
isTerminated(false)
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

    // Main Menu
    if(!mainMenuTexture.loadFromFile("assets/sprites/menu.png"))
    {
        throw std::runtime_error("Failed to load menu.png");
    }
    mainMenuSprite = std::make_unique<sf::Sprite>(mainMenuTexture);

    // Main Menu title
    font = std::make_unique<sf::Font>("assets/fonts/NES.ttf");
    titleText = std::make_unique<sf::Text>(*font);
    titleText->setFillColor(sf::Color({45,105,220}));
    titleText->setOutlineThickness(2.5f);
    titleText->setOutlineColor(sf::Color({160,190,240}));
    titleText->setCharacterSize(28);
    titleText->setScale({3.f,3.2f});
    titleText->setLineSpacing(1.5f);
    titleText->setString("VECTOR ESCAPE");
    titleText->setPosition({90.f,50.f});


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

    checkOnce = false;
    while (m_elapsed >= timestep)
    {

        if(!checkOnce)
        {
            checkOnce = true;
            count++;
            currentFPS = 1.f/m_elapsed;
        }

        update();
        m_elapsed -= timestep;
    }

    draw();
    
    //FPS Display
    if(!mainMenu && !isTerminated)
    {
        // Θέλουμε τα χαμηλά fps να φαίνονται διαφορετικά ότι δείξει η δειγματοληξία
        if(currentFPS <= 50.f || count>=20)
        {
            titleText->setString("FPS: "+std::to_string( static_cast<int>(currentFPS)));
            count = 0;
        }
    }

    m_elapsed += m_clock.restart().asSeconds();
    // Prevent "spiral of death"
    if(m_elapsed > 0.25)
        m_elapsed = 0.25;

    return true;

}

void Game::update()
{

    if(isTerminated)
    {
        return;
    }

    // Game Over
    if(health.gameOver())
    {
        // Will fix it later
        titleText->setFillColor(sf::Color::Red);
        titleText->setOutlineThickness(0.f);
        titleText->setScale({2.5f,2.5f});
        titleText->setString("GAME OVER");
        titleText->setPosition({view.getCenter().x - 319.f,view.getCenter().y - 128.f});
        sound->stopBackgroundMusic();
        isTerminated = true;
        sound->playGameOver();
        return;
    }
    

    // Main Menu
    if(mainMenu)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
        {
            mainMenu = false;
            sound->playBackgroundMusic();
            titleText->setFillColor(sf::Color({100, 255, 100}));
            titleText->setOutlineThickness(0.f);
            titleText->setScale({0.5f,0.5f});
            titleText->setString("FPS:  0");
        }

        return;
    }

    // Update first bitron for positioning the view correctly 
    bitron.updateBitron(map,health);
    map.updateCamera(window,view,bitron.getX(),bitron.getY());

    titleText->setPosition({view.getCenter().x + 400.f,view.getCenter().y - 250.f});

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
        window.draw(*titleText);
    }
    else
    {
        window.draw(*mainMenuSprite);
        window.draw(*titleText);
    }

    window.display();
}