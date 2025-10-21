#include "headers/Bitron.hpp"

Bitron::Bitron(std::shared_ptr<Sounds> sound)
:verticalSpeed(0.0f),
isColliding(false),
onGround(false),
keyPressed(true),
isMoving(false),
resetPosition(false),
onPlatform(false),
advanceMap(true),
isDamaged(false),
currentFrame(0),
animationIterator(0),
damageIterator(0),
sound(sound)

{
    frameTimer = 0.0f;
    
    if(!bitronTexture.loadFromFile("assets/sprites/Bitron.png"))
    {
        throw std::runtime_error("Failed to load Bitron.png");
    }
    bitronSprite = std::make_unique<sf::Sprite>(bitronTexture);
}

void Bitron::updateAnimation()
{

    // Έχει φάει χτύπο
    if(isDamaged)
    {
        if(damageIterator <= 60)
        {
            bitronSprite->setColor( (damageIterator%6 == 0) ? sf::Color(255,255,255,255):sf::Color(255,255,255,128));
            damageIterator++;
        }
        else
        {
            isDamaged = false;
            damageIterator = 0;
            bitronSprite->setColor(sf::Color(255,255,255,255));
        }
    }

    // Only animate if on ground
    if(isMoving && verticalSpeed == 0.f)
    {

        while(animationIterator >= 4)
        {
            animationIterator -= 4;
            // 3 frames
            currentFrame = (currentFrame + 1) % 3;
        }
        animationIterator++;
        bitronSprite->setTextureRect(sf::IntRect({currentFrame*32,32},{32,32}));
    }
    else if(verticalSpeed < 0.f)
    {
        // Πηδάει
        bitronSprite->setTextureRect(sf::IntRect({64,0},{32,32}));
    }
    else if(verticalSpeed > 0.f)
    {
        // Πέφτει
        bitronSprite->setTextureRect(sf::IntRect({32,0},{32,32}));
    }
    else
    {
        // Idle
        bitronSprite->setTextureRect(sf::IntRect({0,0},{32,32}));
        currentFrame = 0;
        animationIterator = 0;
    }

}

void Bitron::updateBitron(mapManager& map,Health& health)
{

    // skipping maps (Cheating!!)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) && advanceMap && map.getCurrentMapIndex() < 8)
    {
        advanceMap = false;
        resetPosition = false;
        map.nextMap();
        return;
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
    {
        advanceMap = true;
    }


    if(!resetPosition)
    {

        switch(map.getCurrentMapIndex())
        {
            case 2:
                x = 16.0f;
                y = 0.0f;
                break;
            case 3:
                x = 64.0f;
                y = 64.0f;
                break;
            case 4:
                x = 64.0f;
                y = 190.0f;
                break;
            case 5:
                x = 64.0f;
                y = 900.0f;
                break;
            case 6:
                x = 64.0f;
                y = 960.0f;
                break;
            case 7:
                x = 718.0f;
                y = 96.0f;
                break;
            case 8:
                x = 16.f;
                y = 1468.f;
                break;
            default:
                x = 16.f;
                y = 256.f;

        }

        verticalSpeed = 0.0f;
        jumpTimer = 0;
        resetPosition = true;
        return;
    }

    // Animation part
    updateAnimation();
 

    // Physics part

    // x-axis
    static std::array<Cell,4> horizontalMovementCheck;
    horizontalMovementCheck = {Cell::Empty,Cell::Empty,Cell::Empty,Cell::Empty};
    // LEFT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
    {
        bitronSprite->setScale({-1.f, 1.f});
        // Set origin to right edge
        bitronSprite->setOrigin({32.f, 0.f});
        isMoving = true;
        faceRight = false;


        horizontalMovementCheck = map.mapCollision(sf::FloatRect({x-movementSpeed,y},{bitronSize.x,bitronSize.y}));

        if(horizontalMovementCheck[0] == Cell::RedTile)
        {
            if(!isDamaged)
            {
                sound->playDie();
                bitronIsDamaged();
                health.damageTaken();
                x += 6.f*movementSpeed;
            }
        }
        else if (horizontalMovementCheck[0] != Cell::BlueTile)
        {
            if(horizontalMovementCheck[2] == Cell::BlueTile)
            {
                // Να τσεκάρω αν είναι από πάνω σε block
                if(verticalSpeed == 0.0f  && !onPlatform)
                     x = std::max<float>(x - movementSpeed, 0);
            }
            else
                x = std::max<float>(x - movementSpeed, 0);
        }
        else
        {
            x = cellSize*floor(x / cellSize);
        }
    }
    // RIGHT
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right))
    {
        bitronSprite->setScale({1.f, 1.f});
        // Reset origin
        bitronSprite->setOrigin({0.f, 0.f});
        isMoving = faceRight = true;


        horizontalMovementCheck = map.mapCollision(sf::FloatRect({x+movementSpeed,y},{bitronSize.x,bitronSize.y}));

        if(horizontalMovementCheck[1] == Cell::RedTile)
        {
            if(!isDamaged)
            {
                sound->playDie();
                bitronIsDamaged();
                health.damageTaken();
                x -= 6.f*movementSpeed;
            }
        }
        else if(horizontalMovementCheck[1] != Cell::BlueTile)
        {
            if(horizontalMovementCheck[3] == Cell::BlueTile)
            {
                // Να τσεκάρω αν είναι από πάνω σε block
                if(verticalSpeed == 0.0f  && !onPlatform)
                    x = std::min<float>(x + movementSpeed, map.getWidth() * cellSize - 32);
            }
            else
                x = std::min<float>(x + movementSpeed, map.getWidth() * cellSize - 32);
        }
        else
        {
            x = cellSize*(floor((x) / cellSize)+1) -32.0f;
        }
    }
    else
    {
        isMoving = false;
    }

    // y-axis
    static std::array<Cell,4> verticalMovementCheck;
    // Fixed the bug! (Αριστερή άκυρη μετακίνηση σε jump)
    if(verticalSpeed < 0.f) verticalMovementCheck = map.mapCollision(sf::FloatRect({x,y+verticalSpeed-0.1f},{bitronSize.x-1.f,bitronSize.y}));
    else verticalMovementCheck = map.mapCollision(sf::FloatRect({x,y+verticalSpeed},{bitronSize.x-1.f,bitronSize.y}));
    // Check for exit tile the 4 corners
    if(std::find(verticalMovementCheck.begin(),verticalMovementCheck.end(),Cell::ExitTile) != verticalMovementCheck.end())
    {
        sound->playNext();
        map.nextMap();
        resetPosition = false;
        return;
    }

    // JUMP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) && keyPressed)
    {
        if(verticalMovementCheck[0] == Cell::TriggerTile || verticalMovementCheck[1] == Cell::TriggerTile)
        {
            sound->playTrigger();
        }
        else if(verticalMovementCheck[0] == Cell::RedTile || verticalMovementCheck[1] == Cell::RedTile)
        {
            verticalSpeed = 0.f;
            keyPressed = false;

            if(!isDamaged)
            {
                sound->playDie();
                bitronIsDamaged();
                health.damageTaken();
                verticalSpeed = 2.f;
            }
        }
        else
        {
            if (onGround || onPlatform)
            {
                sound->playJump();
                onGround = false;
                onPlatform = false;
                verticalSpeed = -4.0f;
                jumpTimer = maxJumpTimer;
            }
            else if((verticalMovementCheck[0] != Cell::BlueTile && verticalMovementCheck[1] != Cell::BlueTile))
            {
                if (jumpTimer > 0)
                    jumpTimer--;
                else
                    keyPressed = false;
            }
            else
            {
                y -= verticalSpeed;
                verticalSpeed = 0.0f;
                keyPressed = false;
            }
        }
    }
    // Πέφτει ή έχουμε αφήσει το Κουμπί
    else
    {
            if(verticalMovementCheck[2] == Cell::TriggerTile || verticalMovementCheck[3] == Cell::TriggerTile)
            {
                sound->playTrigger();
                
            }
            else if(verticalMovementCheck[0] == Cell::RedTile || verticalMovementCheck[1] == Cell::RedTile)
            {
                    if(!isDamaged)
                    {
                        sound->playDie();
                        bitronIsDamaged();
                        health.damageTaken();
                        verticalSpeed = 2.f;
                    }
                    else if(verticalSpeed != 0.f)
                        verticalSpeed = 0.f;
                    else
                    {
                        if(verticalMovementCheck[0] == Cell::RedTile && verticalMovementCheck[1] != Cell::RedTile)
                            x += 6.f*movementSpeed;
                        else
                            x -= 6.f*movementSpeed;
                    }

            }
            else if(verticalMovementCheck[2] == Cell::RedTile || verticalMovementCheck[3] == Cell::RedTile)
            {
                    if(!isDamaged)
                    {
                        sound->playDie();
                        bitronIsDamaged();
                        health.damageTaken();
                        verticalSpeed = -2.0f;
                        onGround = false;
                    }
                    else
                    {
                        verticalSpeed = 0.f;
                        y = cellSize*ceil((y) / cellSize) - 32.f;
                        onGround = true;
                        keyPressed = true;
                    }
            }
            else if((verticalMovementCheck[0] == Cell::BlueTile || verticalMovementCheck[1] == Cell::BlueTile) && !keyPressed)
            {
                y -= verticalSpeed;
                verticalSpeed = 0.0f;
            }
            else if((verticalMovementCheck[2] == Cell::BlueTile || verticalMovementCheck[3] == Cell::BlueTile))
            {
                // Δουλεύει σωστά!
                y = cellSize*ceil((y) / cellSize) - 32.0f;
                verticalSpeed = 0.0f;
                jumpTimer = 0;
                onGround = true;
                onPlatform = false;
                keyPressed = true;
            }
            else
            {
                keyPressed = false;
                // Βαρύτητα
                verticalSpeed = std::min(0.18f + verticalSpeed, 8.0f);
            }
    }

    // Να μην βγεί από πάνω όριο
    if(y >= 0.0f)
        y += verticalSpeed;
    else
    {
        jumpTimer = 0;
        verticalSpeed = 0.0f;
        y = 0.0f;
    }

}

void Bitron::updateBitronFromPlatform(float x,float y,float verticalSpeed,bool onGround,bool onPlatform,bool keyPressed,unsigned char jumpTimer)
{
    this->x=x;
    this->y=y;
    this->verticalSpeed=verticalSpeed;
    this->onGround=onGround;
    this->onPlatform=onPlatform;
    this->keyPressed=keyPressed;
    this->jumpTimer=jumpTimer;
}

void Bitron::bitronIsDamaged()
{
    isDamaged = true;
}

void Bitron::drawBitron(sf::RenderWindow& window)
{

    bitronSprite->setPosition({x,y});
    window.draw(*bitronSprite);
}


