#pragma once

constexpr const unsigned int windowWidth = 1280;
constexpr const unsigned int windowHeight = 720;
constexpr const sf::Vector2f coinSize{18.f,18.f};
constexpr const sf::Vector2f bitronSize{32.f,32.f};
constexpr const sf::Vector2f viewSize{1024.f,512.f};

// Τι θα περιέχει η πίστα μας
enum Cell{
    Empty,
    BlueTile,
    RedTile,
    TriggerTile,
    ExitTile
};
