#include "editornode.h"
#include <iostream>

EditorNode::EditorNode(Entity& entity) :
    entity(entity)
{
    std::cout << "ednode" << std::endl;
    this->rect.setSize(sf::Vector2f(10,10));
    this->rect.setPosition(entity.getPosition().toDrawable());
    this->rect.setFillColor(sf::Color(100,250,50));
}

void EditorNode::setAbsolutePositionImpl(const Position pos, bool sent) {
    this->entity.setAbsolutePosition(pos, sent);
    this->rect.setPosition(pos.toDrawable());
}

Position EditorNode::getPosition() {
    return Position::fromDrawable(this->rect.getPosition());
}

void EditorNode::draw(sf::RenderWindow& window) {
    this->entity.draw(window);
    window.draw(this->rect);
}
