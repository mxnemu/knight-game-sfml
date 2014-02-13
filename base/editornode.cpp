#include "editornode.h"
#include <iostream>

EditorNode::EditorNode(Entity& entity) :
    entity(entity)
{
    std::cout << "ednode" << std::endl;
}

void EditorNode::setAbsolutePositionImpl(const Position pos, bool sent) {
    this->entity.setAbsolutePosition(pos, sent);
    this->rect.setPosition(pos.toDrawable());
}
