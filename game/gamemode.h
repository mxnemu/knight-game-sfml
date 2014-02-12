#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game;
class GameMode {
 public:
    GameMode(Game& game);
    virtual ~GameMode();

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(sf::Time) = 0;
    virtual void draw() = 0;
 protected:
    Game& game;
    sf::View view;
};
