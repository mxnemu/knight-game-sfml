#include "stage.h"

TileSeries&  Stage::addTileSeries(Position pos) {
    this->tileserieses.push_back(TileSeries());
    return this->tileserieses.back();
}

void Stage::draw(sf::RenderWindow& window) {
    for (TileSeries& it : this->tileserieses) {
        it.draw(window);
    }
}
