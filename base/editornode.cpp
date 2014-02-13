#include "editornode.h"

void EditorNode::setAbsolutePositionImpl(const Position pos, bool sent) {
    this->entity.setAbsolutePosition(pos, sent);
    this->rect.setPosition(pos.toDrawable());
}
