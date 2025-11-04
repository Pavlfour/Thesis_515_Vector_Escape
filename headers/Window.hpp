#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "Globals.hpp"
#include "windowText.hpp"

class Window
{
    private:
        sf::View view;
        sf::Image icon;
        sf::RenderWindow window;
        sf::Texture mainMenuTexture,backgroundTexture;
        std::unique_ptr<sf::Sprite> mainMenuSprite,backgroundSprite;
        float centerX, centerY;
        bool isRunning;

    public:

        std::unique_ptr<windowText> text;

        Window();
        bool windowIsDone();
        void drawText(unsigned short currentMapIndex);
        void beginDraw();
        void backgroundDraw();
        void mainMenuDraw();
        void endDraw();
        void firstMapText();
        void updateCamera(float x,float y,unsigned short mapPixelWidth,unsigned short mapPixelHeight);
        void gameOver();
        void winner();

        // Getters
        sf::View& getView() { return view; }
        sf::RenderWindow* GetRenderWindow() { return &window; }
        float getCenterX() const { return centerX; }
        float getCenterY() const { return centerY; }

};