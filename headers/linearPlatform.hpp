#pragma once
#include "platform.hpp"
#include "Bitron.hpp"

// class Bitron;

class linearPlatform : public platform
{

    private:
        bool forward = true;
        float distance;
        sf::Vector2f direction;
        sf::Vector2f startPos;
        sf::Vector2f endPos;
        sf::Vector2f target;

    public:
        linearPlatform(sf::Vector2f startPos,sf::Vector2f endPos,float speed);
        void platformUpdate(Bitron& bitron) override;

};