#ifndef I_AUTHENTICATION_SERVICE_H
#define I_AUTHENTICATION_SERVICE_H

#include <string>

using namespace std;

class IAuthenticationService {
public:
    virtual string login(const string& input) = 0;
    virtual string register_user(const string& input) = 0;
}

/* 
TODO: Ask Yuval, what should the service get and what should it return?,
because the controller should adapt the input to the service language, but i need to specify the service input for every service function becausee of the map implementation.
and what should it return because sometimes i need to return an error and sometimes i need to return a success message.
and how can i save login state in the architecture.
*/

#endif // I_AUTHENTICATION_SERVICE_H