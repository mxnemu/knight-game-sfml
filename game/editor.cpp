#include "editor.h"
#include "editortool.h"
#include "game.h"

Editor::Editor(Game& game, sf::IpAddress serverIp, int port) :
    GameMode(game)
{
    this->connect(serverIp, port);
    this->pallets.push_back(TilePallet("./world/pallets/earth.json"));
    this->activeTool = new tool::AddTile(*this, &this->pallets.back());
}

Stage& Editor::stageRef() {
    return stage;
}

bool Editor::connect(sf::IpAddress serverIp, int port) {
    return false;
}

void Editor::newStage() {
}
void Editor::handleEvent(sf::Event& event) {
    switch (event.type) {
    case sf::Event::MouseButtonPressed: {
        const sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        const Position pos = Position::fromMouse(mousePos, this->view);
        this->activeTool->click(pos);
        break;
    }
    case sf::Event::MouseWheelMoved: {
        float scale = (event.mouseWheel.y > 0 ? 0.02 : -0.02);
        sf::View view = this->game.getWindowRef().getView();
        view.zoom(scale);
        this->game.getWindowRef().setView(view);
        break;
    }
    default:
        break;
    }
}

void Editor::update(sf::Time) {
    
}
void Editor::draw(sf::RenderWindow& window) {
    stage.draw(window);
}
