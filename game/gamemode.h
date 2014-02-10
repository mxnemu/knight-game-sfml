#pragma once
#include <SFML/System.hpp>

class Game;
class GameMode {
 public:
    GameMode(Game& game);
    virtual ~GameMode();
    virtual void update(sf::Time) = 0;
    virtual void draw() = 0;
 protected:
    Game& game;
};
