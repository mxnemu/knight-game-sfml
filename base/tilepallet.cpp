#include "tilepallet.h"
#include "groundtile.h"
#include <SFML/Graphics.hpp>

TilePallet::TilePallet(const std::string path) {
    leftBorderWidth = 0;
    rightBorderWidth = 0;
    tileHeight = 0;
    tileWidth = 0;
    friction = 0;
    restitution = 0;
    nw::JsonReader jr(path);
    this->describe(jr);
    jr.close();
    std::cerr << jr.getErrorMessage() << std::endl;
}

void TilePallet::describe(nw::Describer& de) {
    nw::describe(de, "texture", texture);
    nw::describe(de, "leftBorderWidth", leftBorderWidth);
    nw::describe(de, "rightBorderWidth", rightBorderWidth);
    nw::describe(de, "tileHeight", tileHeight);
    nw::describe(de, "tileWidth", tileWidth);
    nw::describe(de, "friction", friction);
    nw::describe(de, "restitution", restitution);
}

GroundTile TilePallet::create(GroundTile* left, GroundTile* right) {
    sf::Image img;
    img.loadFromFile(std::string("./img/ground/earth.png") + texture);
    sf::Texture* tex = new sf::Texture();
    tex->loadFromImage(img);
    GroundTile ret;
    ret.shape.setTexture(tex);
    if (left && !right) {
        
    } else if (!left && right) {

    } else {

    }
    return ret;
}
