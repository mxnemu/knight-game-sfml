#include <iostream>
#include "server.h"

int main(int argc, const char* argv[]) {
    std::cout << "Hello World" << std::endl;
    Server server;
    server.start(8083);
    server.stopAndWait();
    return 0;
}
