#include "moveable.h"

void Moveable::setAbsolutePosition(const Position pos, bool send) {
    this->setAbsolutePositionImpl(pos, send);
    //this->send();
}
