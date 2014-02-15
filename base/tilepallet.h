
#pragma once
#include <N0Slib.h>
#include "groundtile.h"

class TilePallet {
 public:
    TilePallet(const std::string fileName);
    void describe(nw::Describer& de);
    GroundTile* create(Position pos, GroundTile* left, GroundTile* right);
    
    std::string texture;
    int leftBorderWidth;
    int rightBorderWidth;
    int tileHeight;
    int tileWidth;
    float friction;
    float restitution;
};
