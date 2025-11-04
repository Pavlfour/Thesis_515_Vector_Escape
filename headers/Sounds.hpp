#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>


class Sounds
{
private:

    // Sound Effects
    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer triggerBuffer;
    sf::SoundBuffer dieBuffer;
    sf::SoundBuffer nextBuffer;
    sf::SoundBuffer coinBuffer;
    sf::SoundBuffer zapBuffer;
    sf::SoundBuffer lifeBuffer;
    sf::SoundBuffer shootBuffer;
    sf::SoundBuffer gameOverBuffer;
    sf::SoundBuffer winBuffer;

    sf::Sound* jumpSound;
    sf::Sound* triggerSound;
    sf::Sound* dieSound;
    sf::Sound* nextSound;
    sf::Sound* coinSound;
    sf::Sound* zapSound;
    sf::Sound* lifeSound;
    sf::Sound* shootSound;
    sf::Sound* gameOverSound;
    sf::Sound* winSound;

    // Background music
    sf::Music backgroundMusic;

public:
    Sounds();
    ~Sounds();
    
    void playJump();
    void playTrigger();
    void playDie();
    void playNext();
    void playCoin();
    void playZap();
    void playLife();
    void playShoot();
    void playGameOver();
    void playWin();

    void playBackgroundMusic();
    void stopBackgroundMusic();
    void pauseBackgroundMusic();
};
