#pragma once
#include "moveable.h"

class Entity : public Moveable {
 public:
    //    int getId();
 private:
    int id;
};

namespace action {
class AddEntity {
    
};
} // namespace
