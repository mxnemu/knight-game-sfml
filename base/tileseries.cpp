#include "tileseries.h"

TileSeries::~TileSeries() {
    for (GroundTile* it : tiles) {
        delete it;
    }
}

void TileSeries::addTile(GroundTile* tile) {
    if (tile) {
        this->tiles.push_back(tile);
        this->nodes.push_back(EditorNode(*tile));
    }
}

void TileSeries::setAbsolutePositionImpl(Position pos, bool sent) {
    // TODO move all nodes without sending and send this one
    // remove sent from moveimpl fn header
}

Position TileSeries::getPosition() {
    // TODO median for all node positions
    return Position::fromDrawable(sf::Vector2f(0,0));
}

void TileSeries::draw(sf::RenderWindow& window) {
    for (EditorNode& it : nodes) {
        it.draw(window);
    }
}
