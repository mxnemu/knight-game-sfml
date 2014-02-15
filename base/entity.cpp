#include "entity.h"

Entity::Entity() : Moveable() {
    id = -1;
}

Entity::~Entity() {
    for (std::function<void()>&cb : beforeDeleteCallbacks) {
        cb();
    }
    
}

void Entity::beforeDeleteCallback(std::function<void()> cb) {
    beforeDeleteCallbacks.push_back(cb);
}


std::function<void()> Entity::registerListener(std::function<void()> listener) {
    this->registeredListeners.push_back(listener);
    return listener;
}
