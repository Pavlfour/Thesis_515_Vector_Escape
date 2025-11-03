#pragma once
#include "mapManager.hpp"
#include "Sounds.hpp"
#include "Globals.hpp"
#include "Window.hpp"

enum GameState
{
    MainMenu = 1,
    Running,
    GameOver,
    Finished
};

class Game
{
    public:
        Game();
        bool isRunning();

    private:

        // FPS
        const float timestep = 1.0f / 60.0f;
        sf::Clock m_clock;
        float m_elapsed;

        // Main components
        std::shared_ptr<Sounds> sound;
        GameState gameState{MainMenu};
        Window window;
        mapManager map;
        

        void update();
        void draw();

};
