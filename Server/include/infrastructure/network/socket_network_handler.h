#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#include "infrastructure/network/network_handler.h"

namespace infrastructure {
namespace network {
    class SocketNetworkHandler : public NetworkHandler {
    public:
        SocketNetworkHandler();
        ~SocketNetworkHandler();

        void start() override;
        void get_request() override;
        void send_response() override;
        void stop() override;
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
}
}