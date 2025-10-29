#pragma once
#include <SFML/Graphics.hpp>

class windowText
{
    public:
        windowText()
        {
            font = std::make_unique<sf::Font>("assets/fonts/NES.ttf");
            currentText = std::make_unique<sf::Text>(*font);
        }

        void setMainMenuText()
        {

            currentText->setFillColor(sf::Color({45,105,220}));
            currentText->setOutlineThickness(2.5f);
            currentText->setOutlineColor(sf::Color({160,190,240}));
            currentText->setCharacterSize(28);
            currentText->setScale({3.f,3.2f});
            currentText->setLineSpacing(1.5f);
            currentText->setString("VECTOR ESCAPE");
            currentText->setPosition({90.f,50.f});
        }

        void setGameOverText(float x,float y)
        {
            currentText->setFillColor(sf::Color::Red);
            currentText->setOutlineThickness(0.f);
            currentText->setScale({2.5f,2.5f});
            currentText->setString("GAME OVER");
            currentText->setPosition({x,y});

        }

        void setWinnerText(float x,float y)
        {
            currentText->setFillColor(sf::Color::Yellow);
            currentText->setOutlineThickness(0.f);
            currentText->setScale({2.5f,2.5f});
            currentText->setString("WINNER!");
            currentText->setPosition({x,y});
        }

        // Getter
        sf::Text& getText()
        {
            return *currentText;
        }

    private:
        
        std::unique_ptr<sf::Font> font;
        std::unique_ptr<sf::Text> currentText;
};