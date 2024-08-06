#include <iostream>
// main.cpp
#include "SocketHandler.h"

int main() {
    SocketHandler socketHandler;
    socketHandler.connectToServer("127.13.37.1", "1337");

    std::cin.get();
    return 0;
}