#pragma once
#include "gamemode.h"

class Game {
 public:
    void setMode(GameMode* mode);
 private:
    GameMode* activeMode;
};
