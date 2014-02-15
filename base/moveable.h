#pragma once
#include "position.h"

class Moveable {
 public:
    Moveable();
    void setAbsolutePosition(const Position pos, bool send = true);
 protected:
    virtual void setAbsolutePositionImpl(const Position pos, bool sent) = 0;
};

namespace action {
    class Move {
    };
} // namespace
