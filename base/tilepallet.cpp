#include "tilepallet.h"
#include "groundtile.h"
#include <SFML/Graphics.hpp>
#include "utils.h"

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

GroundTile* TilePallet::create(Position pos, GroundTile* left, GroundTile* right) {
    sf::Image img;
    if (!img.loadFromFile(std::string("./img/ground/") + texture)) {
        return NULL;
    }
    sf::Texture* tex = new sf::Texture();
    if (!tex->loadFromImage(img)) {
        return NULL;
    }
    GroundTile* ret = new GroundTile();
    ret->shape.setTexture(tex);
    ret->shape.setPointCount(4);
    ret->shape.setPoint(0, sf::Vector2f(tileWidth/2, -tileHeight/2));
    ret->shape.setPoint(1, sf::Vector2f(-tileWidth/2, -tileHeight/2));
    ret->shape.setPoint(2, sf::Vector2f(-tileWidth/2, tileHeight/2));
    ret->shape.setPoint(3, sf::Vector2f(tileWidth/2, tileHeight/2));
    ret->setAbsolutePosition(pos, false);

    if (left && !right) {
        ret->shape.setRotation(Utils::rotationTo(pos.toDrawable(), left->shape.getPosition()));
    } else if (!left && right) {
        
    } else {

    }
    return ret;
}
