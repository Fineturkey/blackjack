#ifndef MyApiTestClient_hpp
#define MyApiTestClient_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/web/client/ApiClient.hpp"

/* Begin Api Client code generation */
#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Test API client.
 * Use this client to call application APIs.
 */
class MyApiTestClient : public oatpp::web::client::ApiClient {
  API_CLIENT_INIT(MyApiTestClient)
  API_CALL("GET", "/game/start", getGameStart)
  API_CALL("GET", "/game/addPlayer/{playerName}", getAddPlayer, PATH(oatpp::String, playerName))
  API_CALL("GET", "/game/isOver", getStopGame)
  API_CALL("GET", "/game/deal", getDeal)
  API_CALL("GET", "/game/gameState", getGameState)
  API_CALL("GET", "/game/dealerTurn", getDealerTurn)
  API_CALL("GET", "/game/hit/{playerName}", getHit, PATH(oatpp::String, playerName))
  API_CALL("GET", "/game/stand/{playerName}", getStand, PATH(oatpp::String, playerName))
  API_CALL("GET", "/game/reset", resetGame)
};

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)

#endif  // MyApiTestClient_hpp
