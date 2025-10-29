#pragma once
#include <SFML/Graphics.hpp>

class windowText
{
    public:
        windowText()
        {
            font = std::make_unique<sf::Font>("assets/fonts/SuperMario256.ttf");
            stateText = std::make_unique<sf::Text>(*font);
            coinText = std::make_unique<sf::Text>(*font);

            coinText->setFillColor(sf::Color{72,114,225});
            coinText->setOutlineThickness(1.5f);
            coinText->setOutlineColor(sf::Color::Black);
            coinText->setScale({0.8f,0.8f});
            coinText->setString("COINS:"+std::to_string(0));

            setMainMenuText();
            
        }

        void setMainMenuText()
        {

            stateText->setFillColor(sf::Color({45,105,220}));
            stateText->setOutlineThickness(2.5f);
            stateText->setOutlineColor(sf::Color({160,190,240}));
            stateText->setCharacterSize(30);
            stateText->setScale({3.5f,3.7f});
            stateText->setString("VECTOR ESCAPE");
            stateText->setPosition({190.f,50.f});
        }

        void setGameOverText(float x,float y)
        {
            stateText->setFillColor(sf::Color::Red);
            stateText->setOutlineThickness(0.f);
            stateText->setScale({3.5f,3.5f});
            stateText->setString("GAME OVER");
            stateText->setPosition({x,y});

        }

        void setWinnerText(float x,float y)
        {
            stateText->setFillColor(sf::Color::Yellow);
            stateText->setOutlineThickness(0.f);
            stateText->setScale({3.5f,3.5f});
            stateText->setString("WINNER!");
            stateText->setPosition({x,y});
        }

        void setFirstMapText()
        {
            // first tutorial text
            stateText = std::make_unique<sf::Text>(*font);
            stateText->setFillColor(sf::Color::Black);
            stateText->setOutlineThickness(1.2f);
            stateText->setOutlineColor(sf::Color::White);
            stateText->setCharacterSize(18);
            stateText->setLineSpacing(1.5f);
            stateText->setScale({1.7f,1.7f});
            stateText->setString("USE THE ARROW KEYS TO NAVIGATE\nHOLD THE UP KEY FOR LONGER JUMPS!\nAVOID RED TILES TO PREVENT LOSING HEALTH!!");
            stateText->setPosition({115.f,150.f});
        }

        void setSecondMapText()
        {
            stateText->setPosition({115.f,100.f});
            stateText->setString("ALWAYS AVOID ENEMIES!\nCOLLECT COINS FOR EXTRA LIFE\nACTIVATE TRIGGER TILES TO UPDATE THE MAP");
        }

        void setThirdMapText()
        {
            stateText->setPosition({120.f,40.f});
            stateText->setString("ENJOY AND GOOD LUCK!");
        }

        void updateCoinCounter(unsigned short coinCounter)
        {
            coinText->setString("COINS:"+std::to_string(coinCounter));
        }

        void updateCoinPosition(float x,float y)
        {
            coinText->setPosition({x,y});
        }


        // Getter
        sf::Text& getStateText()
        {
            return *stateText;
        }

        sf::Text& getCoinText()
        {
            return *coinText;
        }

    private:
        
        std::unique_ptr<sf::Font> font;
        std::unique_ptr<sf::Text> stateText;
        std::unique_ptr<sf::Text> coinText;
};