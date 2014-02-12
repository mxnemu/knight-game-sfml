#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

class GroundTile : public Entity {
 public:
    GroundTile();
    sf::ConvexShape shape;
};
