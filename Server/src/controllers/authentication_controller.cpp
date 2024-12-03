// #include "i_controller.h"
// #include "i_service.h"

// #include <map>
// #include <string>
// #include <functional>

// using namespace std;
// class AuthenticationController : public IController {
// private:
//     IService* authentication_service;

//     using RequestHandler = function<string(const string&)>;

//     map<string, RequestHandler> headersMap;
// public:
//     AuthenticationController(IService* authentication_service) : authentication_service(authentication_service){
//         headersMap["login"] = [this](const string& input) { return this->authentication_service->login(input); };
//     }

//     void handle_request(const string& input) override {
        
//     };
// };

#include "AuthenticationController.h"
#include "AuthenticationService.h"
#include <iostream>

AuthenticationController::AuthenticationController(AuthenticationService* service)
    : authService(service) {}

bool AuthenticationController::Login(const std::string& username, const std::string& password) {
    if (authService->Authenticate(username, password)) {
        std::cout << "Login successful!" << std::endl;
        return true;
    } else {
        std::cout << "Invalid credentials!" << std::endl;
        return false;
    }
}

bool AuthenticationController::Signup(const std::string& username, const std::string& password, const std::string& email) {
    if (authService->RegisterUser(username, password, email)) {
        std::cout << "User registered successfully!" << std::endl;
        return true;
    } else {
        std::cout << "Registration failed!" << std::endl;
        return false;
    }
}
