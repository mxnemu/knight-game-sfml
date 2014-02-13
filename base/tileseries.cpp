#include "tileseries.h"

GroundTile& TileSeries::addTile(GroundTile tile) {
    this->nodes.push_back(std::pair<EditorNode, GroundTile>(
                                                            EditorNode(tile),
                                                            tile
                                                            ));
    return this->nodes.back().second;
}

void TileSeries::setAbsolutePositionImpl(Position pos, bool sent) {
    // TODO move all nodes without sending and send this one
    // remove sent from moveimpl fn header
}


