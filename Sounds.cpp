#include "headers/Sounds.hpp"
#include <iostream>

Sounds::Sounds()
{

    if(!jumpBuffer.loadFromFile("assets/sound/jump.wav") || !triggerBuffer.loadFromFile("assets/sound/trigger.wav") || !dieBuffer.loadFromFile("assets/sound/die.wav")
    || !nextBuffer.loadFromFile("assets/sound/next.wav") || !coinBuffer.loadFromFile("assets/sound/coin.wav")       || !zapBuffer.loadFromFile("assets/sound/zap.wav")
    || !lifeBuffer.loadFromFile("assets/sound/life.wav") || !shootBuffer.loadFromFile("assets/sound/shoot.wav")     || !backgroundMusic.openFromFile("assets/sound/music.wav")
    || !gameOverBuffer.loadFromFile("assets/sound/gameover.wav") || !winBuffer.loadFromFile("assets/sound/win.wav"))
    {
        throw std::runtime_error("Failed to load sounds");
    }


    jumpSound = new sf::Sound(jumpBuffer);
    triggerSound = new sf::Sound(triggerBuffer);
    dieSound = new sf::Sound(dieBuffer);
    nextSound = new sf::Sound(nextBuffer);
    coinSound = new sf::Sound(coinBuffer);
    zapSound = new sf::Sound(zapBuffer);
    lifeSound = new sf::Sound(lifeBuffer);
    shootSound = new sf::Sound(shootBuffer);
    gameOverSound = new sf::Sound(gameOverBuffer);
    winSound = new sf::Sound(winBuffer);

    backgroundMusic.setLooping(true);
    backgroundMusic.setVolume(40);

}

Sounds::~Sounds()
{
    delete jumpSound;
    delete triggerSound;
    delete dieSound;
    delete nextSound;
    delete coinSound;
    delete zapSound;
    delete shootSound;
    delete gameOverSound;
    delete winSound;
}

void Sounds::playBackgroundMusic()
{

    backgroundMusic.play();
}

void Sounds::stopBackgroundMusic()
{
    backgroundMusic.stop();
}

void Sounds::pauseBackgroundMusic()
{
    backgroundMusic.pause();
}

void Sounds::playJump()      { jumpSound->play();    }
void Sounds::playTrigger()   { triggerSound->play(); }
void Sounds::playDie()       { dieSound->play();     }
void Sounds::playNext()      { nextSound->play();    }
void Sounds::playCoin()      { coinSound->play();    }
void Sounds::playZap()       { zapSound->play();     }
void Sounds::playLife()      { lifeSound->play();    }
void Sounds::playShoot()     { shootSound->play();   }
void Sounds::playGameOver()  { gameOverSound->play();}
void Sounds::playWin()       { winSound->play();     }