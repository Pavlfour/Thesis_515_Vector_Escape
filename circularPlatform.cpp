#include "headers/circularPlatform.hpp"

circularPlatform::circularPlatform(sf::Vector2f circleCenter, float radius, float speed,bool antiClockwise,float startAngle)
:center(circleCenter),
radius(radius),
speed(speed),
antiClockwise(antiClockwise),
angle(startAngle),
platform()
{
    platformPos = {center.x + radius * std::cos(angle), center.y + radius * std::sin(angle)};
    lastPos = platformPos;
}

void circularPlatform::platformUpdate(Bitron& bitron)
{
    lastPos = platformPos;
    // Update angle based on direction
    if (antiClockwise)
        angle -= speed;
    else
        angle += speed;

    // για να μην γίνει τεράστια η γωνία
    if (angle > 2 * M_PI) angle -= 2 * M_PI;
    if (angle < 0) angle += 2 * M_PI;

    // Update position
    platformPos = {center.x + radius * std::cos(angle),
                   center.y + radius * std::sin(angle)};

    // Movement delta (how much the platform moved this frame)
    sf::Vector2f movement = platformPos - lastPos;

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
