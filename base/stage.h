#pragma once
#include <N0Slib.h>
#include <vector>
#include "groundtile.h"

class Stage {
 public:
    void describe(nw::Describer& de);
    void addTile(GroundTile);

 private:
    std::vector<GroundTile> tiles;
};
