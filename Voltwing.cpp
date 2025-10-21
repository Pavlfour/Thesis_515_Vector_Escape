#include "headers/Voltwing.hpp"

Voltwing::Voltwing(std::vector<sf::Vector2f> points, float speed,std::shared_ptr<Sounds> sound):
pathPoints(std::move(points)),
frameTimer(0.0f),
currentFrame(0),
currentTargetIndex(1),
forward(true),
speed(speed),
sound(sound),
animationIterator(0)
{
    voltwingPos = pathPoints[0];

    if(!voltwingTexture.loadFromFile("assets/sprites/Voltwing.png"))
    {
        throw std::runtime_error("Failed to load Voltwind.png");
    }
    voltwingSprite = std::make_unique<sf::Sprite>(voltwingTexture);
}

bool Voltwing::updateVoltwing(Bitron& bitron)
{
    ////////////////////// Animation part /////////////////////////////////////
    while(animationIterator >= 4)
    {
        animationIterator -= 4;
        // 6 frames
        currentFrame = (currentFrame + 1) % 6;

    }
    animationIterator++;
    voltwingSprite->setTextureRect(sf::IntRect({currentFrame*32,0},{32,32}));
    ////////////////////////////////////////////////////////////////////////////

    // Αλλάξαμε το πλαίσιο ώστε να είναι πιο ακριβής η επαφή με τον παίκτη
    sf::FloatRect voltwingBounds({voltwingPos.x + 6.f, voltwingPos.y + 4.f}, {20.0f, 22.0f});
    sf::FloatRect bitronBounds({bitron.getX(), bitron.getY()}, {32.0f, 32.0f});

    if (bitronBounds.findIntersection(voltwingBounds) && !bitron.getDamageStatus())
    {
        return true;
    }


    sf::Vector2f target = pathPoints[currentTargetIndex];
    direction = target - voltwingPos;
    distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance <= speed  || distance <= 1.f)
    {
        voltwingPos = target;
        // Επόμενο σημείο
        if (forward)
        {
            currentTargetIndex++;
            if (currentTargetIndex >= pathPoints.size())
            {
                currentTargetIndex = pathPoints.size() - 2;
                forward = false;
            }
        }
        else
        {
            if (currentTargetIndex == 0)
            {
                currentTargetIndex = 1;
                forward = true;
            }
            else
                currentTargetIndex--;
        }
    }
    else
    {
        voltwingPos += (direction / distance) * speed;
    }

    return false;

}

void Voltwing::drawVoltwing(sf::RenderWindow& window)
{
    voltwingSprite->setPosition({voltwingPos.x, voltwingPos.y});
    window.draw(*voltwingSprite);
}
