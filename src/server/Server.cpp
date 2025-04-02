/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @date Spring 2025
 */
#include "oatpp/network/Server.hpp"

#include "ServerComponents.hpp"

// note: when we write our controllers just add the include for em
#include "../controller/BlackJackController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/api/ApiController.hpp"

void run() {
  ServerComponent components;

  /* Create Router for HTTP requests routing */
  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  /* Create BlackJackController and add all of its endpoints to router */
  // TODO(team members): Add more shape controllers
  auto controller = std::make_shared<BlackJackController>();
  router->addController(controller);

  /* Create HTTP connection handler with router */
  auto connectionHandler =
      oatpp::web::server::HttpConnectionHandler::createShared(router);

  /* Create TCP connection provider */
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>,
                  connectionProvider);

  /* Create server which takes provided TCP connections and passes them to HTTP
   * connection handler */
  oatpp::network::Server server(connectionProvider, connectionHandler);

  /* Print info about server port */
  OATPP_LOGI("BlackJack Service", "Server running on port %d",
             connectionProvider->getProperty("port").getData());

  /* Run server */
  server.run();
}

int main() {
  oatpp::base::Environment::init();
  run();
  oatpp::base::Environment::destroy();

  return 0;
}
