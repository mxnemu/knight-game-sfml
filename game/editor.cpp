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

void Editor::update(sf::Time) {
    
}
void Editor::draw() {
    
}
