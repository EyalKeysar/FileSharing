#include "i_controller.h"
#include "i_service.h"

#include <map>
#include <string>
#include <functional>

using namespace std;
class AuthenticationController : public IController {
private:
    IService* authentication_service;

    using RequestHandler = function<string(const string&)>;

    map<string, RequestHandler> headersMap;
public:
    AuthenticationController(IService* authentication_service) : authentication_service(authentication_service){
        headersMap["login"] = [this](const string& input) { return this->authentication_service->login(input); };
    }

    void handle_request(const string& input) override {
        
    };
};