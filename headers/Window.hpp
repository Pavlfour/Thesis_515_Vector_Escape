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
        sf::Texture mainMenuTexture;
        sf::Texture backgroundTexture;
        std::unique_ptr<sf::Sprite> mainMenuSprite;
        std::unique_ptr<sf::Sprite> backgroundSprite;
        float centerX, centerY;

    public:

        std::unique_ptr<windowText> text;

        Window();
        
        float getCenterX() const { return centerX; }
        float getCenterY() const { return centerY; }

        bool windowIsDone()
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


        sf::RenderWindow* GetRenderWindow()
        {
            return &window;
        }

        void drawText(unsigned short currentMapIndex)
        {
            if (currentMapIndex < 3)
            {
                window.draw(text->getStateText());
            }
            window.draw(text->getCoinText());
        }

        void beginDraw()
        {
            window.clear();
        }

        void backgroundDraw()
        {
            window.draw(*backgroundSprite);
        }

        void mainMenuDraw()
        {
            window.draw(*mainMenuSprite);
        }

        void endDraw()
        {
            window.display();
        }


        void firstMapText()
        {
            text->setFirstMapText();
        }


        void updateCamera(float x,float y,unsigned short mapPixelWidth,unsigned short mapPixelHeight)
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

        void gameOver()
        {
            text->setGameOverText(view.getCenter().x - 205.f,view.getCenter().y - 128.f);
        }

        void winner()
        {
            text->setWinnerText(view.getCenter().x - 130.f,view.getCenter().y - 128.f);
        }

        sf::View& getView()
        {
            return view;
        }

};