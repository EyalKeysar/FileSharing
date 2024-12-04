#include "controllers/authentication_controller.h"
#include "services/authentication_service.h"
#include "infrastructure/network/socket_network_handler.h"
#include "infrastructure/database/sqlite_repository.h"
#include <memory>

int main() {
    // Create concrete implementations of interfaces
    auto database = std::make_shared<infrastructure::database::SQLiteRepository>("database.db");
    auto network_handler = std::make_shared<infrastructure::network::SocketNetworkHandler>();

    // Inject dependencies into services
    auto auth_service = std::make_shared<services::AuthenticationService>(database);


    // Inject services into controllers
    controllers::AuthenticationController auth_controller(auth_service, network_handler);
    

    // Start network handler (server)
    network_handler->Start();

    // Example interaction
    std::string username = "testUser";
    std::string password = "securePass";
    auth_controller.Signup(username, password);

    network_handler->Stop();
    return 0;
}

