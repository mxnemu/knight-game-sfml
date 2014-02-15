#pragma once
#include <N0Slib.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "tileseries.h"
#include "tilepallet.h"
#include "position.h"

class Stage {
 public:
    void describe(nw::Describer& de);
    TileSeries& addTileSeries(Position pos);

    void draw(sf::RenderWindow& window);
 private:
    std::vector<TileSeries> tileserieses;
};
