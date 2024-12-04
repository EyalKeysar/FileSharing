#include "infrastructure/network/socket_network_handler.h"

namespace infrastructure {
namespace network {

    SocketNetworkHandler::SocketNetworkHandler(){
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0) {
            std::cerr << "WSAStartup failed: " << iResult << std::endl;
            exit(1);
        }
    }

}
}