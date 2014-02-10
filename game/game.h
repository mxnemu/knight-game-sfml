#pragma once
#include "gamemode.h"
#include <SFML/Window.hpp>

class Game {
 public:
    Game();
    void init();
    void setMode(GameMode* mode);

    void loop();
 private:
    GameMode* activeMode;
    sf::Window window;
};
