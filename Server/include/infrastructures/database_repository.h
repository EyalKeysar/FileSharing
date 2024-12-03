#pragma once

#include "domain/user.h"
#include <vector>
#include <string>

namespace infrastructure {

    class DatabaseRepository {
    public:
        virtual ~DatabaseRepository() = default;

        // User-related operations
        virtual bool CreateUser(const domain::User& user) = 0;
        virtual domain::User GetUserById(int id) = 0;
        virtual domain::User GetUserByUsername(const std::string& username) = 0;
        virtual bool UpdateUser(const domain::User& user) = 0;
        virtual bool DeleteUser(int id) = 0;

        // General operations
        virtual bool InitializeDatabase() = 0;
    };

} // namespace infrastructure
