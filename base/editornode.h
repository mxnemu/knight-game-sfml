#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class EditorNode : public Entity {
 public:
    EditorNode(Entity& entity);

    void draw(sf::RenderWindow& window);
    virtual Position getPosition();
 protected:
    virtual void setAbsolutePositionImpl(const Position pos, bool sent);

 private:
    Entity& entity;
    sf::RectangleShape rect;
};
