#pragma once
#include "moveable.h"

class Entity : public Moveable {
 public:
    virtual ~Entity();
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
