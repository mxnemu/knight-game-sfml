#pragma once
#include <base/tilepallet.h>

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
        virtual void click(const Position pos);
    private:
        TilePallet* pallet;
    };

    class Tools {
    public:
        Tools();
        EditorTool emptyTool;
        EditorTool& activeTool;
        std::vector<EditorTool> tools;
    };
    
} // namespace

