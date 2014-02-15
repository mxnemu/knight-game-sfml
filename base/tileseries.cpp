#include "tileseries.h"

GroundTile& TileSeries::addTile(GroundTile tile) {
    this->tiles.push_back(tile);
    this->nodes.push_back(EditorNode(tiles.back()));
    return this->tiles.back();
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
