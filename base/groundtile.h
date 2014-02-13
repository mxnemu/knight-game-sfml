#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

class GroundTile : public Entity {
 public:
    GroundTile();
    virtual void setAbsolutePositionImpl(const Position pos, bool sent);
 private:
    sf::ConvexShape shape;
};
