#include "gamemode.h"
#include "game.h"

GameMode::GameMode(Game& game) :
    game(game)
{
    view.reset(sf::FloatRect(0, 0, 800, 480));
    game.getWindowRef().setView(view);
}

GameMode::~GameMode() {
}
