#include "game.h"

Game::Game() 
    : activeMode(NULL)
{
    init();
}

void Game::init() {
    window.create(sf::VideoMode(800, 480), "Knight Game");
}

void Game::setMode(GameMode* mode) {
    if (this->activeMode) {
        delete this->activeMode;
    }
    this->activeMode = mode;
}


void Game::loop() {
    sf::Event event;
    while (this->window.isOpen()) {
        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                this->activeMode->handleEvent(event);
            }
        }
        this->window.clear(sf::Color::Black);
        this->activeMode->draw(window);
        this->window.display();
    }
}
