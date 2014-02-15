#pragma once
#include <SFML/Graphics.hpp>

class Position {
 public:
    static Position fromMouse(sf::Vector2f pos, sf::View view);
    // TODO default-arg scale with a constant
    static Position fromPhysics(sf::Vector2f pos, float physicsScale);
    static Position fromDrawable(sf::Vector2f pos);

    // TODO default-arg scale with a constant
    sf::Vector2f toPhysics(float physicsScale) const;
    sf::Vector2f toDrawable() const;

    /// Only use with care for transforms or whatever
    sf::Vector2f& rawAccess();
 private:
    Position(sf::Vector2f pos);
    sf::Vector2f pos;
};
