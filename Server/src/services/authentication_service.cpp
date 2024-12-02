#include "include/i_service.h"

#include <iostream>
#include <string>
using namespace std;


class AuthenticationService: public IService {
public:
    void login(const string& input) {
        cout << "Logging in with input: " << input << endl;
    };
};