#include <iostream>
// main.cpp
#include "server_socket_handler.h"

int main() {
    ServerSocketHandler server;
    server.startServer("1337");

    server.acceptConnection();
    std::string message = server.receiveMessage();
    std::cout << "Received message: " << message << std::endl;

    server.sendMessage("Hello from server!");

    std::cin.get();
    return 0;
}