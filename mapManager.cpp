#include "headers/mapManager.hpp"
#include "mapDetailsHandler.cpp"

mapManager::mapManager(Window* window):
sound(std::make_shared<Sounds>()),
bitron(sound),
window(window)
{
    currentMapIndex = 0;
    coinCounter = 0;

    // static components   
    if(!tilesetTexture.loadFromFile("assets/sprites/tileset.png"))
    {
        throw std::runtime_error("Failed to load tileset.png");
    }
    tilesetSprite = std::make_unique<sf::Sprite>(tilesetTexture);

    // Αρχικοποίηση των πιστών στην λίστα
    convertMap("assets/maps/map1.txt");
    convertMap("assets/maps/map2.txt");
    convertMap("assets/maps/map3.txt");
    convertMap("assets/maps/map4.txt");
    convertMap("assets/maps/map5.txt");
    convertMap("assets/maps/map6.txt");
    convertMap("assets/maps/map7.txt");
    convertMap("assets/maps/map8.txt");
    convertMap("assets/maps/map9.txt");
    convertMap("assets/maps/map10.txt");

    // Μόνο για την πρώτη πίστα
    currentMapHeight = mapPool[currentMapIndex].size();
    currentMapWidth = mapPool[currentMapIndex][0].size();
    mapPixelWidth = currentMapWidth * cellSize;
    mapPixelHeight = currentMapHeight * cellSize;

}


void mapManager::addVoltwing(std::initializer_list<sf::Vector2f> points, float speed)
{
    voltwings.emplace_back(std::make_unique<Voltwing>(
        std::vector<sf::Vector2f>(points),
        speed
    ));
}


void mapManager::addLinearPlatform(sf::Vector2f startPos,sf::Vector2f endPos,float speed)
{
    platforms.push_back(std::make_unique<linearPlatform>(startPos,endPos,speed));
}

void mapManager::addCircularPlatform(sf::Vector2f circleCenter, float radius, float speed,bool clockwise,float startAngle)
{
    platforms.push_back(std::make_unique<circularPlatform>(circleCenter,radius,speed,clockwise,startAngle));
}

void mapManager::addBeamlok(sf::Vector2f startPos,sf::Vector2f endPos,float speed)
{
    beamloks.emplace_back(std::make_unique<Beamlok>(startPos,endPos,speed));
}

void mapManager::addCoin(float posX,float posY)
{
    coins.emplace_back(std::make_unique<coin>(posX,posY));
}



void mapManager::convertMap(const std::string& filename)
{
    std::vector<std::vector<Cell>> convertedMap;
    std::ifstream file(filename);
    if(!file.is_open())
    {
        throw std::runtime_error("Failed to load " + filename);
    }

    std::string line;
    
    while(std::getline(file,line))
    {
        std::vector<Cell> newRow;
        for(const auto& character : line)
        {
            switch(character)
            {
                case ' ':
                break;
                case '0':
                newRow.push_back(Empty);
                break;
                case '1':
                newRow.push_back(BlueTile);
                break;
                case '2':
                newRow.push_back(RedTile);
                break;
                case '3':
                newRow.push_back(TriggerTile);
                break;
                case '4':
                newRow.push_back(ExitTile);
                break;

            }
        }
        convertedMap.push_back(newRow);
    }

    mapPool.push_back(convertedMap);

}



void mapManager::drawMap(sf::RenderWindow* window,float centerX,float centerY)
{

    // Έχει γίνει optimization για να ζωγραφίζονται μόνο τα τετράγωνα που είναι στην κεντρική οθόνη
    for (unsigned short a = floor((centerY - viewSize.y/2.f) / static_cast<float>(cellSize)); a < ceil((viewSize.y/2.f + centerY) / static_cast<float>(cellSize)); a++)
    {
        for (unsigned short b = floor((centerX - viewSize.x/2.f) / static_cast<float>(cellSize)); b < ceil((viewSize.x/2.f + centerX) / static_cast<float>(cellSize)); b++)
        {
            if (mapPool[currentMapIndex][a][b] == Cell::Empty)
                continue;
            else if(mapPool[currentMapIndex][a][b] == Cell::BlueTile)
                tilesetSprite->setTextureRect(sf::IntRect({0, 0}, {cellSize, cellSize}));
            else if(mapPool[currentMapIndex][a][b] == Cell::TriggerTile)
                tilesetSprite->setTextureRect(sf::IntRect({0, cellSize}, {cellSize, cellSize}));
            else if(mapPool[currentMapIndex][a][b] == Cell::ExitTile)
                tilesetSprite->setTextureRect(sf::IntRect({cellSize, cellSize}, {cellSize, cellSize}));
            else
                tilesetSprite->setTextureRect(sf::IntRect({cellSize, 0}, {cellSize, cellSize}));

            tilesetSprite->setPosition({static_cast<float>(b * cellSize), static_cast<float>(a * cellSize)});
            window->draw(*tilesetSprite);
        }
    }

    for(auto& plat : platforms)
    {
        plat->drawPlatform(window);
    }

    for(auto& coin : coins)
    {
        coin->drawCoin(window);
    }

    for(auto& voltwing : voltwings)
    {
        voltwing->drawVoltwing(window);
    }

    for(auto& beamlok : beamloks)
    {
        beamlok->drawBeamlok(window);
    }

}

void mapManager::drawMapComponents()
{
    
    drawMap(window->GetRenderWindow(),window->getCenterX(),window->getCenterY());
    window->drawText(currentMapIndex);
    health.drawHealth(window->GetRenderWindow());
    bitron.drawBitron(window->GetRenderWindow());
}

// Η αρίθμηση του πίνακα 0,1,2,...
std::array<Cell,4> mapManager::mapCollision(sf::FloatRect bounds)
{

    // 0 -> κενό
    // 1 -> μπλε
    // 2 -> κόκκινο
    // 3 -> trigger
    // 4 -> exit
    std::array<Cell,4> total = {Cell::Empty,Cell::Empty,Cell::Empty,Cell::Empty};


    // Θέλουμε να ελέγξουμε τα 4 τετράγωνα γύρω από τα όρια του παίκτη
    sf::Vector2f cells[4] =
    {
        // top left cell
        {floorf( bounds.position.x / static_cast<float>(cellSize)),                  floorf(bounds.position.y / static_cast<float>(cellSize))},
        // top right cell
        {floorf((bounds.position.x + bounds.size.x) / static_cast<float>(cellSize)), floorf(bounds.position.y / static_cast<float>(cellSize))},
        // bottom left cell
        {floorf( bounds.position.x / static_cast<float>(cellSize)),                  floorf((bounds.position.y + bounds.size.y) / static_cast<float>(cellSize))},
        // bottom right cell
        {floorf((bounds.position.x + bounds.size.x) / static_cast<float>(cellSize)), floorf((bounds.position.y + bounds.size.y) / static_cast<float>(cellSize))}
    };


    for (unsigned char a = 0; a < 4; ++a)
    {
        short tempX = cells[a].x;
        short tempY = cells[a].y;

        if (tempX >= 0 && tempX < currentMapWidth && tempY >= 0 && tempY < currentMapHeight)
        {
            if (mapPool[currentMapIndex][tempY][tempX] == Cell::BlueTile)
            {
                total[a] = Cell::BlueTile;
            }
            else if (mapPool[currentMapIndex][tempY][tempX] == Cell::RedTile)
            {
                total[a] = Cell::RedTile;
            }
            else if (mapPool[currentMapIndex][tempY][tempX] == Cell::TriggerTile)
            {
                sound->playTrigger();
                total[a] = Cell::TriggerTile;
                updateMapComponets(this,tempX,tempY);
            }
            else if (mapPool[currentMapIndex][tempY][tempX] == Cell::ExitTile)
            {
                total[a] = Cell::ExitTile;
            }
        }
    }

    return total;
}


void mapManager::nextMap()
{
    platforms.clear();
    coins.clear();
    voltwings.clear();
    beamloks.clear();
    currentMapIndex++;

    if(currentMapIndex < 3)
    {
        window->updateText(currentMapIndex);
    }

    currentMapHeight = mapPool[currentMapIndex].size();
    currentMapWidth = mapPool[currentMapIndex][0].size();

    mapPixelWidth = currentMapWidth * cellSize;
    mapPixelHeight = currentMapHeight * cellSize;

    addMapComponents(this);
 
}


void mapManager::updatePlatforms()
{
    for(auto& plat : platforms)
    {
        plat->platformUpdate(bitron);
    }

}

void mapManager::updateCoins()
{

for (auto it = coins.begin(); it != coins.end(); )
{

    if ((*it)->coinUpdate(sf::FloatRect({bitron.getX(),bitron.getY()},bitronSize)))
    {
        sound->playCoin();
        it = coins.erase(it);
        coinCounter++;
        if(coinCounter == 50)
        {
            coinCounter = 0;
            health.addHealth();
            sound->playLife();
        }
        window->updateCoinText(coinCounter);
    }
    else
    {
        ++it;
    }

}

}

void mapManager::updateVoltwings()
{
    for(auto& voltwing : voltwings)
    {
        
        if((*voltwing).updateVoltwing(sf::FloatRect({bitron.getX(),bitron.getY()},bitronSize),bitron.getDamageStatus()))
        {
                health.damageTaken();
                bitron.bitronIsDamaged();
                sound->playZap();
        }
    }
}

void mapManager::updateBeamloks()
{
    // decoupled sound from beamloks and lasers
    for(auto& beamlok : beamloks)
    {
        switch((*beamlok).updateBeamlok(sf::FloatRect({bitron.getX(),bitron.getY()},bitronSize),bitron.getDamageStatus(),this))
        {
            case 1:
                sound->playShoot();
                break;
            case 2:
                sound->playDie();
                health.damageTaken();
                bitron.bitronIsDamaged();
                break;
            default:
                break;
        }
    }
}

void mapManager::updateMapComponents()
{
    // Unit under test
    if(bitron.updateBitron(*this))
        health.damageTaken();

    updatePlatforms();
    window->updateCamera(bitron.getX(),bitron.getY(),mapPixelWidth,mapPixelHeight);
    updateCoins();
    updateVoltwings();
    updateBeamloks();
    health.updateHealth(window->getView());
}


bool mapManager::checkForTiles(short startX,short endX,short y)
{
    for( short i = startX ; i < endX ; ++i )
    {
        if(mapPool[currentMapIndex][y][i] == Cell::BlueTile) return true;
    }

    return false;
}

bool mapManager::projectileCollicion(short x,short y)
{
    short tempX = x;
    if (x >= currentMapWidth) return false;
    else if(x <= -1) tempX=0;
    return mapPool[currentMapIndex][y][tempX] == Cell::Empty;
}
