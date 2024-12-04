// server_socket_handler.cpp
#include "server_socket_handler.h"
#include <iostream>

// Constructor
ServerSocketHandler::ServerSocketHandler() {
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        exit(1);
    }
}

ServerSocketHandler::~ServerSocketHandler() {
    cleanup();
}

void ServerSocketHandler::startServer(const std::string& port) {
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET; // AF_INET is used to specify the IPv4 address family
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP; // IPPROTO_TCP is used to specify the TCP protocol
    hints.ai_flags = AI_PASSIVE; // AI_PASSIVE is used to specify that the address is intended for a server

    iResult = getaddrinfo(NULL, port.c_str(), &hints, &result);
    if (iResult != 0) {
        std::cerr << "getaddrinfo failed: " << iResult << std::endl;
        WSACleanup();
        exit(1);
    }

    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        std::cerr << "Error at socket(): " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        WSACleanup();
        exit(1);
    }

    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "bind failed: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        exit(1);
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "listen failed: " << WSAGetLastError() << std::endl;
        closesocket(ListenSocket);
        WSACleanup();
        exit(1);
    }

    std::cout << "Server started, waiting for connections on port " << port << std::endl;
}

void ServerSocketHandler::acceptConnection() {
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        std::cerr << "accept failed: " << WSAGetLastError() << std::endl;
        closesocket(ListenSocket);
        WSACleanup();
        exit(1);
    }

    std::cout << "Client connected." << std::endl;
}

void ServerSocketHandler::sendMessage(const std::string& message) {
    iResult = send(ClientSocket, message.c_str(), (int)message.length(), 0);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "send failed: " << WSAGetLastError() << std::endl;
        closesocket(ClientSocket);
        WSACleanup();
        exit(1);
    }

    std::cout << "Bytes sent: " << iResult << std::endl;
}

std::string ServerSocketHandler::receiveMessage() {
    iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
    if (iResult > 0) {
        std::cout << "Bytes received: " << iResult << std::endl;
        return std::string(recvbuf, iResult);
    } else if (iResult == 0) {
        std::cout << "Connection closing..." << std::endl;
    } else {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    }
    return "";
}

void ServerSocketHandler::cleanup() {
    if (ClientSocket != INVALID_SOCKET) {
        closesocket(ClientSocket);
        ClientSocket = INVALID_SOCKET;
    }
    if (ListenSocket != INVALID_SOCKET) {
        closesocket(ListenSocket);
        ListenSocket = INVALID_SOCKET;
    }
    WSACleanup();
}
