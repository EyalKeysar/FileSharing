#pragma once

namespace infrastructure {
namespace network {

    class NetworkHandler {
    public:
        virtual void start() = 0;
        virtual void get_request() = 0;
        virtual void send_response() = 0;
        virtual void stop() = 0;
        virtual ~NetworkHandler() = default;
    };

}
}