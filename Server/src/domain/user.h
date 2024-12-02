#pragma once

#include <string>

namespace domain {

    class User
    {
    private:
        int id;
        std::string username;
        std::string password;

    public:
        // Constructor
        User(int id, const std::string& username, const std::string& password)
            : id(id), username(username), password(password) {}

        // Getters
        int getId() const { return id; }
        const std::string& getUsername() const { return username; }
        const std::string& getPassword() const { return password; }

        // Setters
        void setId(int id) { this->id = id; }
        void setUsername(const std::string& username) { this->username = username; }
        void setPassword(const std::string& password) { this->password = password; }
    };
}