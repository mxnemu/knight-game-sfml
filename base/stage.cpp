#include "stage.h"

TileSeries&  Stage::addTileSeries(Position pos) {
    this->tileserieses.push_back(TileSeries());
    return this->tileserieses.back();
}

void Stage::draw(sf::RenderWindow& window) {
    for (auto it = this->tileserieses.begin(); it != this->tileserieses.end(); ++it) {
        (*it).draw(window);
    }
}
