#include "headers/linearPlatform.hpp"

linearPlatform::linearPlatform(sf::Vector2f startPos,sf::Vector2f endPos,float speed)
: platform()
{
    this->speed = speed;
    this->startPos = startPos;
    this->platformPos = startPos;
    this->endPos = endPos;
}

void linearPlatform::platformUpdate(Bitron& bitron)
{
    // update the position of the platform
    target = forward ? endPos : startPos;
    direction = target - platformPos;
    distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f movement = (direction / distance) * speed;

    if (distance <= speed)
        forward = !forward;
    else
        platformPos += movement;


    // Παίρνουμε τα τρέχοντα δεδομένα του παίκτη για να ελέγξουμε σύγκρουση
    // και ξανά ανανέωση
    float x = bitron.getX();
    float y = bitron.getY();
    float verticalSpeed = bitron.getVerticalSpeed();
    bool onGround = bitron.getOnGround();
    bool onPlatform = bitron.getOnPlatform();
    bool keyPressed = bitron.getKeyPressed();
    unsigned char jumpTimer = bitron.getJumpTimer();

    sf::FloatRect playerBounds({x, y}, {32.f, 32.f});
    sf::FloatRect platformBounds({platformPos.x,platformPos.y},{64.f,64.f});

    
    if (playerBounds.findIntersection(platformBounds))
    {

        float playerBottom = y + 32.0f;
        float playerTop = y;
        float playerRight = x + 32.0f;
        float playerLeft = x;
        
        float platformTop = platformBounds.position.y;
        float platformBottom = platformBounds.position.y + platformBounds.size.y;
        float platformLeft = platformBounds.position.x;
        float platformRight = platformBounds.position.x + platformBounds.size.x;

        float overlapLeft = playerRight - platformLeft;
        float overlapRight = platformRight - playerLeft;
        float overlapTop = playerBottom - platformTop;
        float overlapBottom = platformBottom - playerTop;

        bool fromLeft = overlapLeft < overlapRight;
        bool fromTop = overlapTop < overlapBottom;

        float minOverlapX = fromLeft ? overlapLeft : overlapRight;
        float minOverlapY = fromTop ? overlapTop : overlapBottom;

        if (minOverlapY < minOverlapX)
        {
            
            // Vertical collision
            if (fromTop && verticalSpeed >= 0.0f)
            {

                y = platformPos.y - 32.0f;
                // Move Bitron with platform
                x += movement.x;
                y += movement.y;

                verticalSpeed = 0.0f;

                onGround = true;
                onPlatform = true;
                keyPressed = true;


            }
            else if (!fromTop)
            {
                y = platformBottom + verticalSpeed + speed;
                verticalSpeed += 0.18f;
                keyPressed = false;
            }
            
        }
        else
        {
            // Horizontal collision (platform pushes player sideways)
            if (fromLeft)
                x = platformLeft - 32.0f;
            else
                x = platformRight;

        }
    }

    // Update Bitron's state
    bitron.updateBitronFromPlatform(x,y,verticalSpeed,onGround,onPlatform,keyPressed,jumpTimer);

}
