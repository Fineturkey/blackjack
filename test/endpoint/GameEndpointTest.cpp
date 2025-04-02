/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @author Sofiah Plarison <s.plarisan@uleth.ca>
 * @date Spring 2025
 */
#include "GameEndpointTest.hpp"

#include <iostream>
#include <memory>

#include "../app/MyApiTestClient.hpp"
#include "../app/TestComponent.hpp"
#include "../include/controller/Game.hpp"
#include "../src/controller/BlackJackController.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"

void GameStartTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Call server API */
        auto response = client->getGameStart();

        /* Assert that server responds with 200 */
        OATPP_ASSERT(response->getStatusCode() == 200);

        /* Assert that the response body contains the expected message */
        auto responseBody = response->readBodyToString();
        OATPP_ASSERT(responseBody == "Game started");
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void AddPlayerTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Call server API */
        oatpp::String playerName = "testPlayer";
        auto response = client->getAddPlayer(playerName);

        /* Assert that server responds with 200 */
        OATPP_ASSERT(response->getStatusCode() == 200);

        /* Assert that the response body contains the expected message */
        auto responseBody = response->readBodyToString();
        OATPP_ASSERT(responseBody == "Player added");
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void StopGameTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Call server API */
        auto response = client->getStopGame();

        /* Assert that server responds with 200 */
        OATPP_ASSERT(response->getStatusCode() == 200);

        /* Assert that the response body contains the expected message */
        auto responseBody = response->readBodyToString();
        OATPP_ASSERT(responseBody == "Game is over!");
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void DealTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Call server API */
        auto response = client->getDeal();

        /* Assert that server responds with 200 */
        OATPP_ASSERT(response->getStatusCode() == 200);

        /* Assert that the response body contains the expected message */
        auto responseBody = response->readBodyToString();
        OATPP_ASSERT(responseBody == "Game dealt");
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void DealerTurnTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Call server API */
        auto startGameResponse = client->getGameStart();
        OATPP_ASSERT(startGameResponse->getStatusCode() == 200);

        /* Add a player */
        oatpp::String playerName = "testPlayer";
        auto addPlayerResponse = client->getAddPlayer(playerName);
        OATPP_ASSERT(addPlayerResponse->getStatusCode() == 200);

        auto dealResponse = client->getDeal();
        OATPP_ASSERT(dealResponse->getStatusCode() == 200);

        auto dealerTurnResponse = client->getDealerTurn();
        OATPP_ASSERT(dealerTurnResponse->getStatusCode() == 200);

        auto responseBody = dealerTurnResponse->readBodyToString();
        OATPP_ASSERT(responseBody->find("testPlayer") != std::string::npos);

        /* Check for specific cases in the response */
        OATPP_ASSERT(responseBody->find("busted") != std::string::npos ||
                     responseBody->find("wins") != std::string::npos ||
                     responseBody->find("loses") != std::string::npos ||
                     responseBody->find("pushes (tie)") != std::string::npos);
        
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void GameStateTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Start the game */
        auto startGameResponse = client->getGameStart();
        OATPP_ASSERT(startGameResponse->getStatusCode() == 200);

        /* Add a player */
        oatpp::String playerName = "testPlayer";
        auto addPlayerResponse = client->getAddPlayer(playerName);
        OATPP_ASSERT(addPlayerResponse->getStatusCode() == 200);

        /* Deal cards to the player */
        auto dealResponse = client->getDeal();
        OATPP_ASSERT(dealResponse->getStatusCode() == 200);

        /* Retrieve the game's state */
        auto gameStateResponse = client->getGameState();
        OATPP_ASSERT(gameStateResponse->getStatusCode() == 200);

        auto gameDto =
            gameStateResponse->readBodyToDto<oatpp::Object<GameDto>>(
                objectMapper.get());

        /* Dealer Assertions */
        OATPP_ASSERT(gameDto->dealer);
        OATPP_ASSERT(gameDto->dealer->hand->size() > 0);
        OATPP_ASSERT(gameDto->dealer->handValue > 0);

        /* Player Assertions */
        OATPP_ASSERT(gameDto->players);
        OATPP_ASSERT(gameDto->players->size() > 0);

        auto playerDto = gameDto->players[0];
        OATPP_ASSERT(playerDto);
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void HitTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Call server API */
        oatpp::String playerName = "Player1";
        auto response = client->getHit(playerName);

        /* Assert that server responds with 404 */
        /* Scenario when its a null player*/
        OATPP_ASSERT(response->getStatusCode() == 404);

        /* Assert that the response body contains the expected message */
        auto responseBody = response->readBodyToString();
        OATPP_ASSERT(responseBody == "Player not found");

        /* Add player to the game using the addPlayer endpoint */
        auto addPlayerResponse = client->getAddPlayer(playerName);
        OATPP_ASSERT(addPlayerResponse->getStatusCode() == 200);

        /* Call the stand endpoint again */
        /* Except 200 since player is in game now */
        auto response2 = client->getHit(playerName);
        OATPP_ASSERT(response2->getStatusCode() == 200);

        /* Read response body as PlayerDto */
        auto playerDto = response2->readBodyToDto<oatpp::Object<PlayerDto>>(
            objectMapper.get());

        /* Assertions */
        OATPP_ASSERT(playerDto);
        OATPP_ASSERT(playerDto->name == playerName);
        OATPP_ASSERT(playerDto->hand->size() > 0);
        OATPP_ASSERT(playerDto->handValue > 0);
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void StandTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Call server API */
        oatpp::String playerName = "Player1";
        auto response = client->getStand(playerName);

        /* Assert that server responds with 404 */
        OATPP_ASSERT(response->getStatusCode() == 404);

        /* Assert that the response body contains the expected message */
        auto responseBody = response->readBodyToString();
        OATPP_ASSERT(responseBody == "Player not found");

        /* Add player to the game using the addPlayer endpoint */
        auto addPlayerResponse = client->getAddPlayer(playerName);
        OATPP_ASSERT(addPlayerResponse->getStatusCode() == 200);

        /* Call the stand endpoint again */
        auto response2 = client->getStand(playerName);
        OATPP_ASSERT(response2->getStatusCode() == 200);

        auto responseBody2 = response2->readBodyToString();
        OATPP_ASSERT(responseBody2 == "Player stands");
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ResetGameTest::onRun() {
  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Get object mapper component */
  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                  objectMapper);

  /* Add BlackJackController endpoints to the router of the test server */
  runner.addController(std::make_shared<BlackJackController>());

  /* Run test */
  runner.run(
      [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);

        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                        objectMapper);

        /* Create http request executor for Api Client */
        auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
                clientConnectionProvider);

        /* Create Test API client */
        auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Reset game state */
        auto resetResponse = client->resetGame();
        OATPP_ASSERT(resetResponse->getStatusCode() == 200);

        /* Call server API */
        auto response = client->resetGame();

        /* Assert that server responds with 200 */
        OATPP_ASSERT(response->getStatusCode() == 200);

        /* Assert that the response body contains the expected message */
        auto responseBody = response->readBodyToString();
        OATPP_ASSERT(responseBody == "Game reset");
      },
      std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));
}
