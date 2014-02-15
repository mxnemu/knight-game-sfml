#include "tileseries.h"

TileSeries::~TileSeries() {
    for (GroundTile* it : tiles) {
        delete it;
    }
}

void TileSeries::addTile(GroundTile* tile) {
    this->tiles.push_back(tile);
    this->nodes.push_back(EditorNode(*tile));
}

void TileSeries::setAbsolutePositionImpl(Position pos, bool sent) {
    // TODO move all nodes without sending and send this one
    // remove sent from moveimpl fn header
}

void TileSeries::draw(sf::RenderWindow& window) {
    for (EditorNode& it : nodes) {
        it.draw(window);
    }
}
