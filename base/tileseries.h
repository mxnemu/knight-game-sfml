#pragma once
#include "editornode.h"
#include "groundtile.h"
#include <SFML/System.hpp>

class TileSeries : public Entity {
 public:
    GroundTile& addTile(GroundTile tile);
    void setAbsolutePositionImpl(Position pos, bool sent);
    virtual void draw(sf::RenderWindow& window);
 private:
    std::vector<EditorNode> nodes;
    std::vector<GroundTile> tiles;
};
