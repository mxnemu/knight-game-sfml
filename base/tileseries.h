#pragma once
#include "editornode.h"
#include "groundtile.h"
#include <SFML/System.hpp>

class TileSeries : public Entity {
 public:
    GroundTile& addTile(GroundTile tile);
    void setAbsolutePositionImpl(Position pos, bool sent);
 private:
    std::vector<std::pair<EditorNode, GroundTile> > nodes;
};
