#include "position.h"

Position::Position(sf::Vector2f pos) {
    this->pos = pos;
}

Position Position::fromMouse(sf::Vector2f pos, sf::View view) {
    const sf::Transform t = view.getTransform();
    return Position(t.transformPoint(pos));
}

Position Position::fromPhysics(sf::Vector2f pos, float physicsScale) {
    return Position(pos * physicsScale);
}

sf::Vector2f Position::toPhysics(float physicsScale) const {
    return this->pos / physicsScale;
}
sf::Vector2f Position::toDrawable() const {
    return this->pos;
}

sf::Vector2f& Position::rawAccess() {
    return this->pos;
}

