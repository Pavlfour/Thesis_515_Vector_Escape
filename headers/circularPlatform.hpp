#pragma once
#include "platform.hpp"
#include "Bitron.hpp"

class circularPlatform : public platform
{

    private:
        float speed;
        float angle;
        float radius;
        bool clockwise;
        sf::Vector2f center;
        sf::Vector2f lastPos;

    public:
        circularPlatform(sf::Vector2f circleCenter, float radius, float speed,bool clockwise = true,float startAngle = 0.0f);
        void platformUpdate(Bitron& bitron) override;

};