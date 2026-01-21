#include "headers/Game.hpp"

Game::Game():
m_elapsed(0.f),
map(&window)
{
    m_clock.restart();
    srand(time(nullptr));
}

bool Game::isRunning()
{
    if(window.windowIsDone())
        return false;

    while (m_elapsed >= timestep)
    {
        update();
        m_elapsed -= timestep;
    }

    draw();
    
    m_elapsed += m_clock.restart().asSeconds();

    return true;
}

void Game::update()
{

    switch(gameState)
    {
        case GameState::MainMenu:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
            {
                gameState = Running;
                map.mapEventAssist();
            }
            break;
        case GameState::Running:
            
            if(map.checkHealth())
            {
                window.gameOver();
                map.mapEventAssist(2);
                gameState = GameOver;
                return;
            }
            else if(map.getCurrentMapIndex() == 9)
            {
                window.winner();
                map.mapEventAssist(3);
                gameState = Finished;
                return;
            }
            map.updateMapComponents();
            break;
        case GameState::GameOver:
            break;
        case GameState::Finished:
            map.updateBitron();
            break;
    }

}

void Game::draw()
{
    window.beginDraw();

    switch(gameState)
    {
        case GameState::MainMenu:
            window.mainMenuDraw();
            break;
        default:
            window.backgroundDraw();
            map.drawMapComponents();
    }

    window.endDraw();
}