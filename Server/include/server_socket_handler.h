// server_socket_handler.h
#ifndef SERVERSOCKETHANDLER_H
#define SERVERSOCKETHANDLER_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

class ServerSocketHandler {
public:
    ServerSocketHandler();  // Constructor
    ~ServerSocketHandler(); // Destructor

    void startServer(const std::string& port); // Function to start the server
    void acceptConnection();                   // Function to accept a client connection
    void sendMessage(const std::string& message); // Function to send a message to the client
    std::string receiveMessage();              // Function to receive a message from the client

private:
    WSADATA wsaData;
    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;
    struct addrinfo *result = nullptr, hints;
    int iResult;
    char recvbuf[512];
    int recvbuflen = 512;

    void cleanup();
};

#endif // SERVERSOCKETHANDLER_H
