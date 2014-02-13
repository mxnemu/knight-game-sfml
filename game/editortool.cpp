#include "editortool.h"
#include "editor.h"

EditorTool::EditorTool(Editor& editor) :
    editor(editor)
{
}

namespace tool {

void AddTile::click(const Position pos) {
    this->editor.stageRef().addTileSeries(*this->pallet, pos);
}

Tools::Tools(Editor& editor) :
    emptyTool(editor)
    activeTool(emptyTool)
{
    
}

} // namespace
