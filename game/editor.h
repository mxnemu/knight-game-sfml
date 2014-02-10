#pragma once
#include "gamemode.h"
#include <SFML/Network.hpp>

class Editor : public GameMode {
 public:
    Editor(Game& game, sf::IpAddress serverIp, int port);
    void newStage();

    virtual void update(sf::Time) final;
    virtual void draw() final;

    bool connect(sf::IpAddress serverIp, int port);
};
