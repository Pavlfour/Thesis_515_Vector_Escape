#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
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
        std::unique_ptr<windowText> text;

    public:

        Window();
        bool windowIsDone();
        void drawText(unsigned short currentMapIndex);

        void updateText(unsigned short currentMapIndex)
        {
            switch(currentMapIndex)
            {
                case 1:
                    text->setSecondMapText();
                    break;
                case 2:
                    text->setThirdMapText();
                    break;
                default:
                    break;
            }

        }

        void updateCoinText(unsigned short coinCounter)
        {
            text->updateCoinCounter(coinCounter);
        }

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