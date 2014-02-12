#include "editor.h"

Editor::Editor(Game& game, sf::IpAddress serverIp, int port) 
    : GameMode(game)
{
    this->connect(serverIp, port);
}

bool Editor::connect(sf::IpAddress serverIp, int port) {
    return false;
}

void Editor::newStage() {
}
void Editor::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        // TODO move into editorMouseAction
        if (this->activePallete) {
            const sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
            const Position pos = Position::fromMouse(mousePos, this->view);
            this->stage.addTileSeries(*this->activePallete, pos);
        }
    }
}

void Editor::update(sf::Time) {
    
}
void Editor::draw() {
    
}
