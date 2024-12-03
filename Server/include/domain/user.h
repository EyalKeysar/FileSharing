#pragma once

#include <string>

namespace domain {

class User {
public:
    User(int id, const std::string& username, const std::string& password);

    int GetId() const;
    std::string GetUsername() const;
    std::string GetPassword() const;

    void SetUsername(const std::string& username);
    void SetPassword(const std::string& password);

private:
    int id_;
    std::string username_;
    std::string password_;
};

}  // namespace domain
