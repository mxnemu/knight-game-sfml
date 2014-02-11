#pragma once
#include "gamemode.h"
#include <SFML/Graphics.hpp>

class Game {
 public:
    Game();
    void init();
    void setMode(GameMode* mode);

    void loop();
 private:
    GameMode* activeMode;
    sf::RenderWindow window;
};
