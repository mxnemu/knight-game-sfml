#include "editortool.h"
#include "editor.h"

EditorTool::EditorTool(Editor& editor) :
    editor(editor)
{
}

namespace tool {

AddTile::AddTile(Editor& editor) :
    EditorTool(editor),
    pallet(NULL),
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

    this->series->addTile(this->pallet->create(NULL, NULL));
}

} // namespace
