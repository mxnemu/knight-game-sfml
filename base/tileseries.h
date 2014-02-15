#pragma once
#include "editornode.h"
#include "groundtile.h"
#include <SFML/System.hpp>

class TileSeries : public Entity {
 public:
    virtual ~TileSeries();
    void addTile(GroundTile* tile);
    
    Position getPosition();
    virtual void draw(sf::RenderWindow& window);
 protected:
    void setAbsolutePositionImpl(Position pos, bool sent);
 private:
    std::vector<EditorNode> nodes;
    std::vector<GroundTile*> tiles;
};
