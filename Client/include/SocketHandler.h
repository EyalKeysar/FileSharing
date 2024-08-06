// SocketHandler.h
#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

class SocketHandler {
public:
    SocketHandler();  // Constructor
    ~SocketHandler(); // Destructor

    void connectToServer(const std::string& serverAddress, const std::string& port); // Function declaration

    void sendMessage(const std::string& message);

    std::string receiveMessage();

private:
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = nullptr, hints;
    int iResult;
    char recvbuf[512];
    int recvbuflen = 512;
};

#endif // SOCKETHANDLER_H
