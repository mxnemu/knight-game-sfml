#pragma once
#include <N0Slib.h>
#include <vector>
#include <SFML/System.hpp>
#include "tileseries.h"
#include "tilepallet.h"
#include "position.h"

class Stage {
 public:
    void describe(nw::Describer& de);
    void addTileSeries(TilePallet& pallet, Position pos);

 private:
    std::vector<TileSeries> tileserieses;
};
