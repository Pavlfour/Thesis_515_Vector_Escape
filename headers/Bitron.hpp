#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Sounds.hpp"
#include "Health.hpp"
#include "Globals.hpp"
#include <algorithm>

class mapManager;
class Sounds;

class Bitron
{
    private:

        float x,y,verticalSpeed,frameTimer;
        unsigned char jumpTimer;
        const unsigned char maxJumpTimer = 20;
        const float movementSpeed = 2.50f;
        bool onGround,keyPressed,isMoving,resetPosition,onPlatform,
        isColliding,faceRight,advanceMap,isDamaged;


        short currentFrame,animationIterator,damageIterator;

        sf::Texture bitronTexture;
        std::unique_ptr<sf::Sprite> bitronSprite;

        std::shared_ptr<Sounds> sound;

    public:
        Bitron(std::shared_ptr<Sounds> sound);

        void bitronIsDamaged();
        void updateAnimation();
        void updateBitron(mapManager& map,Health& health);
        void drawBitron(sf::RenderWindow* window);
    
        // Getters
        float getX(){return x;}
        float getY(){return y;}
        unsigned char getJumpTimer(){return jumpTimer;}
        float getVerticalSpeed(){return verticalSpeed;}
        bool getOnGround(){return onGround;}
        bool getOnPlatform(){return onPlatform;}
        bool getKeyPressed(){return keyPressed;}
        bool getDamageStatus() const {return isDamaged;}
        bool getBitronDirection()const{return faceRight;}

        // Setters
        void changeResetPosition(){resetPosition = false;}
        void updateBitronFromPlatform(float x,float y,float verticalSpeed,bool onGround,bool onPlatform,bool keyPressed,unsigned char jumpTimer);
        void setDeadSprite();

};