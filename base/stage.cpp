#include "stage.h"

TileSeries&  Stage::addTileSeries(Position pos) {
    this->tileserieses.push_back(TileSeries());
    return this->tileserieses.back();
}
