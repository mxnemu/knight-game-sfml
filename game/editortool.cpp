#include "editortool.h"
#include "editor.h"

EditorTool::EditorTool(Editor& editor) :
    editor(editor)
{
}

namespace tool {

AddTile::AddTile(Editor& editor, TilePallet* pallet) :
    EditorTool(editor),
    pallet(pallet),
    series(NULL)
{
}

void AddTile::click(const Position pos) {
    if (!this->pallet) {
        return;
    }
    if (!this->series) {
        this->series = &this->editor.stageRef().addTileSeries(pos);
        /*
          series.beforeRemoveCallback(registerListener([this]() {
                    this->series = NULL;
                }));
        */
        this->click(pos);
        return;
    }

    GroundTile* tile = this->pallet->create(NULL, NULL);
    tile->setAbsolutePosition(pos, false);
    this->series->addTile(tile);
}

} // namespace
