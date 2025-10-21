#include "headers/Beamlok.hpp"

Beamlok::Beamlok(sf::Vector2f startPos,sf::Vector2f endPos,float speed,std::shared_ptr<Sounds> sound):
sound(sound),
currentFrame(0),
animationIterator(0),
forward(true),
attackMode(false),
fire(false)
{

    this->startPos = startPos;
    this->endPos = endPos;
    this->speed = speed;
    this->beamlokPos = startPos;



    if(!beamlokTexture.loadFromFile("assets/sprites/Beamlok.png"))
    {
        throw std::runtime_error("Failed to load Beamlok.png");
    }
    beamlokSprite = std::make_unique<sf::Sprite>(beamlokTexture);

}

void Beamlok::updateBeamlok(Bitron& bitron,mapManager* currentMap,Health& health)
{

    ///////////////////////////////////////// Animation part ///////////////////////////////////////////////////////
    if(!attackMode)
    {

        while(animationIterator >= 4)
        {
            animationIterator -= 4;
            // 3 frames
            currentFrame = (currentFrame + 1) % 3;
        }
        animationIterator++;
        beamlokSprite->setTextureRect(sf::IntRect({currentFrame*32,0},{32,32}));
 
        if(forward)
        {
            // Κοιτάζει δεξιά
            beamlokSprite->setScale({1.f,1.f});
            beamlokSprite->setOrigin({0.f,0.f});
        }
        else
        {
            // Κοιτάζει αριστερά
            beamlokSprite->setScale({-1.f,1.f});
            beamlokSprite->setOrigin({32.f,0.f});
        }
    }
    else
    {
        if(!fire)
        {
            animationIterator = 0;
            currentFrame = 0;
            fire = true;
        }
        else if(currentFrame < 2)
        {
            while(animationIterator >= 10)
            {
                animationIterator -= 10;
                currentFrame++;
            }
            beamlokSprite->setTextureRect(sf::IntRect({currentFrame*32,32},{32,32}));
            animationIterator++;
        }
        else
        {
            animationIterator++;

            if(animationIterator >= 30)
            {
                sound->playShoot();
                float offSetX = (forward) ? (beamlokPos.x + 28.f) : (beamlokPos.x - 6.f);
                attackMode = false;
                fire = false;
                currentFrame = 0;
                animationIterator = 0;
                beamlokSprite->setTextureRect(sf::IntRect({0,0},{32,32}));
                projectiles.emplace_back(std::make_unique<laser>(forward,sf::Vector2f{offSetX,beamlokPos.y+19.f},sound));
            }
        }
 
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // Σε ποιά θέση είναι ο Beamlok
    short beamlokX = floor(beamlokPos.x / 64.f);

    // Σε ποιά θέση είναι ο Bitron
    short bitronX = floor(bitron.getX() / 64.f);

    // Η θέση στο Y
    short height = floor(beamlokPos.y / 64.f);

    // Πρέπει να τσεκάρω αν υπάρχουν blue tiles ανάμεσά τους
    bool tileExist = currentMap->checkForTiles(std::min(beamlokX,bitronX),std::max(beamlokX,bitronX),height);

    // Range
    float rangeY = std::abs(bitron.getY() - beamlokPos.y);
    float rangeX = std::abs(bitron.getX() - beamlokPos.x);
    
    bool sight{false};
    // Beamlok facing Bitron
    if(forward)
    {
        if( (bitron.getX() - beamlokPos.x) > 0) sight = true;
    }
    else
    {
        if( (beamlokPos.x - bitron.getX()) > 0) sight = true;
    }

    if ((!attackMode) && (rangeY < 32.f) && (rangeX < 384.f) && sight && !tileExist)
    {
        attackMode = true;
    }
    else if(!attackMode)
    {

        target = forward ? endPos : startPos;
        direction = target - beamlokPos;
        distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        sf::Vector2f movement = (direction / distance) * speed;

        if (distance <= speed)
            forward = !forward;
        else
            beamlokPos += movement;

    }


    for(auto pro = projectiles.begin(); pro != projectiles.end();)
    {
        if(!((*pro)->updateLaser(currentMap,bitron,health)))
        {
            pro = projectiles.erase(pro);
        }
        else
        {
            pro++;
        }
    }

}



void Beamlok::drawBeamlok(sf::RenderWindow& window)
{

    beamlokSprite->setPosition({beamlokPos.x, beamlokPos.y});



    for(auto& pro : projectiles)
    {
        pro->drawLaser(window);
    }

    window.draw(*beamlokSprite);
}