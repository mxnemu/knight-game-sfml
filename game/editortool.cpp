#include "editortool.h"
#include "editor.h"

EditorTool::EditorTool(Editor& editor) :
    editor(editor)
{
}

namespace tool {

AddTile::AddTile(Editor& editor) :
    EditorTool(editor)
{
}

void AddTile::click(const Position pos) {
    this->editor.stageRef().addTileSeries(*this->pallet, pos);
}

} // namespace
