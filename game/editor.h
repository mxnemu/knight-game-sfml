#pragma once
#include <SFML/Network.hpp>
#include <base/stage.h>
#include <base/groundtile.h>

#include "gamemode.h"
#include "editortool.h"

class Editor : public GameMode {
 public:
    Editor(Game& game, sf::IpAddress serverIp, int port);
    void newStage();

    virtual void handleEvent(sf::Event& event);
    virtual void update(sf::Time) final;
    virtual void draw() final;

    bool connect(sf::IpAddress serverIp, int port);
    Stage& stageRef();

 private:
    Stage stage;
    EditorTool* activeTool;
};
