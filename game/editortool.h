#pragma once
#include <base/tilepallet.h>
#include <base/tileseries.h>

class Editor;

class EditorTool {
 public:
    EditorTool(Editor& editor);
    virtual void click(const Position pos) {}
 protected:
    Editor& editor;
};

namespace tool {

    class AddTile : public EditorTool {
    public:
        AddTile(Editor& editor, TilePallet* pallet = NULL);
        virtual void click(const Position pos);
    private:
        TilePallet* pallet;
        TileSeries* series;
    };
} // namespace

