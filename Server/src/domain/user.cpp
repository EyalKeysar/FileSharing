#include "domain/user.h"

namespace domain {

User::User(int id, const std::string& username, const std::string& password)
    : id_(id), username_(username), password_(password) {}

int User::GetId() const { return id_;}
std::string User::GetUsername() const { return username_;}
std::string User::GetPassword() const { return password_;}

void User::SetUsername(const std::string& username) { username_ = username;}
void User::SetPassword(const std::string& password) { password_ = password;}

}  // namespace domain
