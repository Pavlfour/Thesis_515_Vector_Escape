#pragma once
#include "mapManager.hpp"
#include "Window.hpp"

enum GameState;

class Game
{
    public:
        Game();
        bool isRunning();

    private:

        // 60 FPS
        const float timestep = 1.0f / 60.0f;
        sf::Clock m_clock;
        float m_elapsed;

        // Main components
        GameState gameState{MainMenu};
        Window window;
        mapManager map;

        void update();
        void draw();

};
