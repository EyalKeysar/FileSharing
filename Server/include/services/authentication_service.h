#pragma once

#include "infrastructure/database/database_repository.h"
#include <memory>
#include <string>

namespace services {

class AuthenticationService {
public:
    explicit AuthenticationService(std::shared_ptr<infrastructure::database::DatabaseRepository> db);

    bool Login(const std::string& username, const std::string& password);
    bool Signup(const std::string& username, const std::string& password);

private:
    std::shared_ptr<infrastructure::database::DatabaseRepository> db_;
};

}  // namespace services
