#include "server.h"
#include <iostream>

Server::Server() :
    running(false)
{
}

Server::~Server() {
    this->stopAndWait();
}

bool Server::start(int port) {
    if (listener.listen(port) != sf::Socket::Done) {
        return false;
    }
    
    Server* server = this;
    this->thread = std::thread([&server]() {
            server->running = true;
            server->exec();
        });
    return true;
}

void Server::stop() {
    this->running = false;
    this->listener.close();
}

void Server::stopAndWait() {
    this->stop();
    if (this->thread.joinable()) {
        this->thread.join();
    }
}

void Server::exec() {
    return;
    while (this->listener.getLocalPort() != 0) {
        std::cout << this->running << std::endl;
        sf::TcpSocket socket;
        if (this->listener.accept(socket) == sf::Socket::Done) {
            std::cout << "got connection" << std::endl;
        }
    }
}
