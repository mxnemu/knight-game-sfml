#pragma once
#include "editornode.h"
#include "groundtile.h"
#include <SFML/System.hpp>

class TileSeries {
 public:
    
 private:
    std::vector<std::pair<EditorNode, GroundTile> > nodes;
};
