#pragma once
#include "mapManager.hpp"
#include "Bitron.hpp"
#include "Sounds.hpp"
#include "Globals.hpp"
#include "Health.hpp"
#include "windowText.hpp"

class Game
{
    public:
        Game();
        bool isRunning();

    private:
        bool mainMenu;

        // Main Components
        sf::RenderWindow window;
        sf::Image icon;
        sf::View view;
        std::shared_ptr<windowText> text;
        std::shared_ptr<Sounds> sound;
        Bitron bitron;
        mapManager map;
        Health health;


        // Main Menu
        sf::Texture mainMenuTexture;
        std::unique_ptr<sf::Sprite> mainMenuSprite;



        // Basic Functions
        void update();
        void draw();


        // FPS
        const float timestep = 1.0f / 60.0f;
        sf::Clock m_clock;
        float m_elapsed;

        bool isTerminated,isFinished;


};
