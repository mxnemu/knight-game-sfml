#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

class GroundTile : public Entity {
 public:
    GroundTile();
    virtual ~GroundTile();

    virtual void draw(sf::RenderWindow& window);
    virtual Position getPosition();
    // private:
    sf::ConvexShape shape;

 protected:
    virtual void setAbsolutePositionImpl(const Position pos, bool sent);
};
