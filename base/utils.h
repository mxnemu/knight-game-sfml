#pragma once
#include <SFML/System.hpp>

class Utils {
    template<class T>
    static T rotationTo(sf::Vector2<T> origin, sf::Vector2<T> b) {
        return atan2(origin.x - b.x , b.y - origin.y);
    }
};
