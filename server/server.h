#include <SFML/Network.hpp>
#include <thread>

class Server {
 public:
    Server();
    virtual ~Server();
    bool start(int port);
    void stop();
    void stopAndWait();
 private:
    void exec();

    bool running;
    sf::TcpListener listener;
    std::thread thread;
    std::vector<sf::TcpSocket> sockets;
};
