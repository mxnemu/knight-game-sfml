#include "groundtile.h"

GroundTile::GroundTile() : Entity() {
}

GroundTile::~GroundTile() {
}

Position GroundTile::getPosition() {
    return Position::fromDrawable(shape.getPosition());
}

void GroundTile::setAbsolutePositionImpl(const Position pos, bool sent) {
    this->shape.setPosition(pos.toDrawable());
}

void GroundTile::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
