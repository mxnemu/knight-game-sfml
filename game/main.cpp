#include <iostream>
#include <server.h>
#include "game.h"
#include "editor.h"

int main(int argc, const char* argv[]) {
    std::cout << "Hello World" << std::endl;
    int port = 8083;

    Server server;
    server.start(port);

    Game game;

    Editor* editor = new Editor(game, sf::IpAddress(127,0,0,1), port);
    editor->newStage();

    game.setMode(editor);

    server.stopAndWait();
    return 0;
}
