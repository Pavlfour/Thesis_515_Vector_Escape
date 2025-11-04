#include "headers/Game.hpp"

Game::Game():
sound(std::make_shared<Sounds>()),
map(sound,&window),
m_elapsed(0.f)
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
                sound->playBackgroundMusic();
            }
            break;
        case GameState::Running:
            
            if(map.checkHealth())
            {
                window.gameOver();
                sound->stopBackgroundMusic();
                sound->playGameOver();
                map.bitronDies();
                gameState = GameOver;
                return;
            }
            else if(map.getCurrentMapIndex() == 9)
            {
                window.winner();
                sound->stopBackgroundMusic();
                sound->playWin();
                gameState = Finished;
                return;
            }
            map.updateMapComponents();
            break;
        case GameState::GameOver:
            window.gameOver();
            break;
        case GameState::Finished:
            map.updateBitron();
            window.winner();
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