#pragma once
#include "moveable.h"
#include <SFML/Graphics.hpp>

class Entity : public Moveable {
 public:
    Entity();
    virtual ~Entity();

    virtual void draw(sf::RenderWindow& window) = 0;
    //    int getId();
    // FIXME better callback management, create an Observable class for this
    void beforeDeleteCallback(std::function<void()> cb);
 private:
    std::function<void()> registerListener(std::function<void()>);

    int id;
    std::vector<std::function<void()> > beforeDeleteCallbacks;
    // this instance registered them
    std::vector<std::function<void()> > registeredListeners;
};

namespace action {
class AddEntity {
    
};
} // namespace
