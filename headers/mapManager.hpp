#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cmath>
#include <memory>

#include "Globals.hpp"
#include "Sounds.hpp"
#include "platform.hpp"
#include "circularPlatform.hpp"
#include "linearPlatform.hpp"
#include "Bitron.hpp"
#include "coin.hpp"
#include "Voltwing.hpp"
#include "Health.hpp"
#include "Beamlok.hpp"
#include "laser.hpp"
#include "windowText.hpp"
#include "Window.hpp"

class windowText;
class platform;
class circularPlatform;
class Bitron;
class coin;
class Voltwing;
class Health;
class Sounds;
class Beamlok;
class laser;

class mapManager
{

    private:
        unsigned short currentMapIndex,currentMapHeight,currentMapWidth,coinCounter;
        float mapPixelWidth,mapPixelHeight,centerX,centerY;

        std::vector<std::vector<std::vector<Cell>>> mapPool;
        std::vector<std::unique_ptr<platform>> platforms;
        std::vector<std::unique_ptr<coin>> coins;
        std::vector<std::unique_ptr<Voltwing>> voltwings;
        std::vector<std::unique_ptr<laser>> lasers;
        std::shared_ptr<Sounds> sound;
        sf::Texture tilesetTexture;
        std::unique_ptr<sf::Sprite> tilesetSprite;

        Bitron bitron;
        Health health;
        

    public:

        mapManager(Window* window);

        // Utils
        Window* window;
        void convertMap(std::vector<std::vector<unsigned char>> map);
        std::array<Cell,4> mapCollision(sf::FloatRect bounds);
        std::vector<std::unique_ptr<Beamlok>> beamloks;
        bool checkForTiles(short startX,short endX,short y);
        bool projectileCollicion(short x,short y);

        // Map filling functions
        void addCircularPlatform(sf::Vector2f circleCenter, float radius, float speed,bool clockwise,float startAngle);
        void addLinearPlatform(sf::Vector2f startPos,sf::Vector2f endPos,float speed);
        void addCoin(float posX,float posY);
        void addBeamlok(sf::Vector2f startPos,sf::Vector2f endPos,float speed);
        void addVoltwing(std::initializer_list<sf::Vector2f> points, float speed);

        // Update
        void nextMap();
        void checkPlatformCollision(sf::Sprite& platform);
        void updatePlatforms();
        void updateCoins();
        void updateVoltwings();
        void updateBeamloks();
        void updateBitron() { bitron.updateBitron(*this); }
        void updateMapComponents();

        // Draw
        void drawMap(sf::RenderWindow* window,float centerX,float centerY);
        void drawMapComponents();

        // Getters
        std::vector<std::vector<std::vector<Cell>>>& getMapPool(){return mapPool;}
        unsigned short getCurrentMapIndex() const {return currentMapIndex;}
        unsigned short getHeight()const{return currentMapHeight;}
        unsigned short getWidth()const{return currentMapWidth;}
        unsigned short getMapPixelWidth()const{return mapPixelWidth;}
        unsigned short getMapPixelHeight()const{return mapPixelHeight;}
        bool checkHealth() const {return health.gameOver();}

        void mapEventAssist(unsigned char event=1)
        {
            switch(event)
            {
                case 1:
                    sound->playBackgroundMusic();
                    break;
                case 2:
                    sound->stopBackgroundMusic();
                    sound->playGameOver();
                    bitron.setDeadSprite();
                    break;
                case 3:
                    sound->stopBackgroundMusic();
                    sound->playWin();
                    break;
                default:
                    break;
            }
        }
};
