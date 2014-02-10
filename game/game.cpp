#include "game.h"

void Game::setMode(GameMode* mode) {
    if (this->activeMode) {
        delete this->activeMode;
    }
    this->activeMode = mode;
}
