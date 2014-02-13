#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class EditorNode : public Entity {
 public:
    EditorNode(Entity& entity);
 protected:
    virtual void setAbsolutePositionImpl(const Position pos, bool sent);

 private:
    Entity& entity;
    sf::RectangleShape rect;
};
