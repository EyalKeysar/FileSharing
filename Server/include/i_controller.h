#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <string>

class IController {
public:
    virtual void handle_request(const std::string& request) = 0;
};

#endif // ICONTROLLER_H
