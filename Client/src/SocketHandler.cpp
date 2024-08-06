// MyClass.cpp
#include "SocketHandler.h"
#include <iostream>

SocketHandler::SocketHandler() {
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed with error: " << iResult << std::endl;
        exit(1);
    }
}

SocketHandler::~SocketHandler() {
    closesocket(ConnectSocket);
    WSACleanup();
}

void SocketHandler::connectToServer(const std::string& serverAddress, const std::string& port) {
    std::cout << "Connecting to server: " << serverAddress << " on port: " << port << std::endl;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo(serverAddress.c_str(), port.c_str(), &hints, &result);
    if (iResult != 0) {
        std::cerr << "getaddrinfo failed with error: " << iResult << std::endl;
        WSACleanup();
        exit(1);
    }
    
    ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        std::cerr << "Error at socket(): " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        WSACleanup();
        exit(1);
    }

    iResult = connect(ConnectSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        std::cerr << "Unable to connect to server!" << std::endl;
        WSACleanup();
        exit(1);
    }

    std::cout << "Connected to server!" << std::endl;

}

void SocketHandler::sendMessage(const std::string& message) {
    iResult = send(ConnectSocket, message.c_str(), message.length(), 0);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "send failed with error: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        exit(1);
    }
}

std::string SocketHandler::receiveMessage() {
    iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
    if (iResult > 0) {
        return std::string(recvbuf, iResult);
    } else if (iResult == 0) {
        std::cerr << "Connection closed" << std::endl;
    } else {
        std::cerr << "recv failed with error: " << WSAGetLastError() << std::endl;
    }
    return "";
}

