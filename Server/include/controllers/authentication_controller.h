#pragma once

#include "services/authentication_service.h"
#include "infrastructure/network/network_handler.h"
#include <memory>
#include <string>

namespace controllers {

class AuthenticationController {
public:
    AuthenticationController(
        std::shared_ptr<services::AuthenticationService> auth_service,
        std::shared_ptr<infrastructure::network::NetworkHandler> network_handler);
        

    void Signup(const std::string& username, const std::string& password);
    void Login(const std::string& username, const std::string& password);

private:
    std::shared_ptr<services::AuthenticationService> auth_service_;
    std::shared_ptr<infrastructure::network::NetworkHandler> network_handler_;
};

}  // namespace controllers
