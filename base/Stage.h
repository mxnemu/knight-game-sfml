#include "N0Strain.h"

class Stage {
    void describe(nw::Describer& de);

 private:
    vector<sf::Vector2f> groundPositions;
};
