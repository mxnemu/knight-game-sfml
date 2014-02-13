#include "editor.h"
#include "editortool.h"

Editor::Editor(Game& game, sf::IpAddress serverIp, int port) :
    GameMode(game)
{
    this->tools.push(EditorTool());
    this->connect(serverIp, port);
}

Stage& stageRef() {
    return stage;
}

bool Editor::connect(sf::IpAddress serverIp, int port) {
    return false;
}

void Editor::newStage() {
}
void Editor::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        // TODO move into editorMouseAction
        const sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        const Position pos = Position::fromMouse(mousePos, this->view);
        this->tools.activeTool.click(pos);
        
    }
}

void Editor::update(sf::Time) {
    
}
void Editor::draw() {
    
}
