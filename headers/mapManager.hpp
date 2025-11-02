#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cmath>
#include <algorithm>
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
        sf::Texture backgroundTexture;
        std::unique_ptr<sf::Sprite> backgroundSprite;
        sf::Texture tilesetTexture;
        std::unique_ptr<sf::Sprite> tilesetSprite;

        

    public:

        mapManager(std::shared_ptr<Sounds> sound,std::shared_ptr<windowText> text);

        std::shared_ptr<windowText> text;

        // utils
        void convertMap(std::vector<std::vector<unsigned char>> map);
        void drawMap(sf::RenderWindow& window);
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
        void updateCamera(sf::RenderWindow& window,sf::View& view,float x,float y);
        void updatePlatforms(Bitron& bitron);
        void updateCoins(Bitron& bitron,Health& health);
        void updateVoltwings(Bitron& bitron,Health& health);
        void updateCoinsText(sf::View& view);
        void updateBeamloks(Bitron& bitron,Health& health);
        bool checkForTiles(short startX,short endX,short y);
        bool projectileCollicion(short x,short y);

        // Getters
        std::vector<std::vector<std::vector<Cell>>>& getMapPool(){return mapPool;}
        unsigned short getCurrentMapIndex() const {return currentMapIndex;}
        unsigned short getHeight()const{return currentMapHeight;}
        unsigned short getWidth()const{return currentMapWidth;}
};