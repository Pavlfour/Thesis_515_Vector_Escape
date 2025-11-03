#pragma once
#include <SFML/Graphics.hpp>
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
#define cellSize 64

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
        Window* window;
        mapManager(std::shared_ptr<Sounds> sound,Window* window);

        // utils
        void convertMap(std::vector<std::vector<unsigned char>> map);
        void drawMap(sf::RenderWindow* window,float centerX,float centerY);
        std::array<Cell,4> mapCollision(sf::FloatRect bounds);
        std::vector<std::unique_ptr<Beamlok>> beamloks;

        // Map filling
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
        bool checkForTiles(short startX,short endX,short y);
        bool projectileCollicion(short x,short y);

        void updateMapComponents()
        {
            bitron.updateBitron(*this,health);
            window->updateCamera(bitron.getX(),bitron.getY(),mapPixelWidth,mapPixelHeight);
            updatePlatforms();
            updateCoins();
            updateVoltwings();
            updateBeamloks();
            health.updateHealth(window->getView());
        }

        void drawMapComponents()
        {
            
            drawMap(window->GetRenderWindow(),window->getCenterX(),window->getCenterY());
            window->drawText(currentMapIndex);
            health.drawHealth(window->GetRenderWindow());
            bitron.drawBitron(window->GetRenderWindow());
        }

        // Getters
        std::vector<std::vector<std::vector<Cell>>>& getMapPool(){return mapPool;}
        unsigned short getCurrentMapIndex() const {return currentMapIndex;}
        unsigned short getHeight()const{return currentMapHeight;}
        unsigned short getWidth()const{return currentMapWidth;}
        unsigned short getMapPixelWidth()const{return mapPixelWidth;}
        unsigned short getMapPixelHeight()const{return mapPixelHeight;}
        bool checkHealth() const {return health.gameOver();}


        void bitronDies() {  bitron.setDeadSprite();  }
};
