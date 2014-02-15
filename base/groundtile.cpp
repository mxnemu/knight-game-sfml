#include "groundtile.h"

GroundTile::GroundTile() {
}

GroundTile::~GroundTile() {
}

void GroundTile::setAbsolutePositionImpl(const Position pos, bool sent) {
    this->shape.setPosition(pos.toDrawable());
}

void GroundTile::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
