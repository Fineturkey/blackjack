/**
 * @author Austin Savoie <austin.savoie@uleth.ca>, Eugene Gu <e.gu@uleth.ca>
 * @date Spring 2025
 */
#ifndef BLACKJACKCONTROLLER_HPP_INCLUDED
#define BLACKJACKCONTROLLER_HPP_INCLUDED

#include <memory>
#include <string>
#include <vector>

#include "../../include/controller/Game.hpp"
#include "../../include/model/Dealer.hpp"
#include "../../include/model/Deck.hpp"
#include "../../include/view/CardUI.hpp"
#include "../../include/view/GameUI.hpp"
#include "../../include/view/PlayerView.hpp"
#include "../dto/CardDTOs.hpp"
#include "../dto/GameDTOs.hpp"
#include "../dto/PlayerDTOs.hpp"
#include "../dto/PlayerListDTOs.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)  ///< Begin Codegen

// Global objects for Endpoint functions
CardUI* cardUI = new CardUI();
PlayerView* playerView = new PlayerView(cardUI);
GameUI* gameUI = new GameUI(playerView);
Deck* deck = new Deck();
Dealer* dealer = new Dealer(deck);
Game* game = new Game(gameUI, dealer);

/**
 * BlackJackController BlackJackController.hpp "BlackJackController.hpp"
 * @brief Controller for the BlackJack game endpoints.
 */
class BlackJackController : public oatpp::web::server::api::ApiController {
 public:
  /**
   * Constructor with object mapper.
   * @param objectMapper - default object mapper used to serialize/deserialize
   * DTOs.
   */
  BlackJackController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
                                      objectMapper))
      : oatpp::web::server::api::ApiController(objectMapper) {}

  ADD_CORS(addPlayer)  // Needed to allow for cross domain access
  ENDPOINT("GET", "/game/addPlayer/{playerName}", addPlayer,
           PATH(String, playerName)) {
    auto player = new Player(playerName);
    game->addPlayer(player);

    return createResponse(Status::CODE_200, "Player added");
  }

  ADD_CORS(startGame)  // Needed to allow for cross domain access
  ENDPOINT("GET", "/game/start", startGame) {
    delete game;
    auto dto = GameDto::createShared();
    gameUI = new GameUI(new PlayerView(new CardUI()));
    dealer = new Dealer(new Deck());
    game = new Game(gameUI, dealer);

    gameUI->displayGameName();

    return createResponse(Status::CODE_200, "Game started");
  }

  ADD_CORS(stopGame)  // Needed to allow for cross domain access
  ENDPOINT("GET", "/game/isOver", stopGame) {
    game->checkWinner();
    return createResponse(Status::CODE_200, "Game is over!");
  }

  ADD_CORS(deal)  // Needed to allow for cross domain access
  ENDPOINT("GET", "/game/deal", deal) {
    game->deal();
    return createResponse(Status::CODE_200, "Game dealt");
  }

  ADD_CORS(dealerTurn)  // Needed to allow for cross domain access
  ENDPOINT("GET", "/game/dealerTurn", dealerTurn) {
    game->dealerTurn();
    std::string result;
    int dealerValue = dealer->checkStatus();

    for (auto player : game->getPlayers()) {
      int playerValue = player->getHandValue();

      if (player->isBusted()) {
        result += player->getName() + " busted.\n";
      } else if (dealerValue > 21 || playerValue > dealerValue) {
        result += player->getName() + " wins.\n";
      } else if (playerValue < dealerValue) {
        result += player->getName() + " loses.\n";
      } else {
        result += player->getName() + " pushes (tie).\n";
      }
    }

    return createResponse(Status::CODE_200, result);
  }

  ADD_CORS(gameState)
  ENDPOINT("GET", "/game/gameState", gameState) {
    auto gameDto = GameDto::createShared();

    // Add dealer information
    auto dealerDto = DealerDto::createShared();
    dealerDto->hand = {};
    std::vector<Card*> dealerCards = dealer->getHand();
    for (auto card : dealerCards) {
      auto cardDto = CardDto::createShared();
      cardDto->rank = cardUI->displayRank(card->getRank());
      cardDto->suit = cardUI->displaySuit(card->getSuit());
      dealerDto->hand->push_back(cardDto);
    }
    dealerDto->handValue = dealer->checkStatus();
    gameDto->dealer = dealerDto;

    // Add player information
    gameDto->players = {};
    std::vector<Player*> gamePlayers = game->getPlayers();
    for (auto player : gamePlayers) {
      auto playerDto = PlayerDto::createShared();
      playerDto->hand = {};
      playerDto->name = player->getName();
      std::vector<Card*> playerCards = player->getHand();
      for (auto card : playerCards) {
        auto cardDto = CardDto::createShared();
        cardDto->rank = cardUI->displayRank(card->getRank());
        cardDto->suit = cardUI->displaySuit(card->getSuit());
        playerDto->hand->push_back(cardDto);
      }
      playerDto->handValue = player->getHandValue();
      playerDto->isBusted = player->isBusted() ? "true" : "false";
      gameDto->players->push_back(playerDto);
    }

    return createDtoResponse(Status::CODE_200, gameDto);
  }

  ADD_CORS(hit)  // Needed to allow for cross domain access
  ENDPOINT("GET", "/game/hit/{playerName}", hit, PATH(String, playerName)) {
    auto player = game->getPlayerByName(playerName);
    if (player == nullptr) {
      return createResponse(Status::CODE_404, "Player not found");
    }

    if (player->isBusted()) {
      return createResponse(Status::CODE_400, "Player is busted");
    } else {
      player->addCard(dealer->dealSingleCard());

      auto playerDTO = PlayerDto::createShared();
      playerDTO->hand = {};
      playerDTO->name = player->getName();
      std::vector<Card*> cards = player->getHand();
      for (auto card : cards) {
        auto cardDTO = CardDto::createShared();
        cardDTO->rank = cardUI->displayRank(card->getRank());
        cardDTO->suit = cardUI->displaySuit(card->getSuit());
        playerDTO->hand->push_back(cardDTO);
      }
      playerDTO->handValue = player->getHandValue();

      return createDtoResponse(Status::CODE_200, playerDTO);
    }
  }

  ADD_CORS(stand)  // Needed to allow for cross domain access
  ENDPOINT("GET", "/game/stand/{playerName}", stand, PATH(String, playerName)) {
    auto player = game->getPlayerByName(playerName);
    if (player == nullptr) {
      return createResponse(Status::CODE_404, "Player not found");
    }

    player->stand();

    return createResponse(Status::CODE_200, "Player stands");
  }

  ADD_CORS(resetGame)  // Needed to allow for cross domain access
  ENDPOINT("GET", "/game/reset", resetGame) {
    delete game;
    gameUI = new GameUI(new PlayerView(new CardUI()));
    dealer = new Dealer(new Deck());
    game = new Game(gameUI, dealer);

    return createResponse(Status::CODE_200, "Game reset");
  }
};

#include OATPP_CODEGEN_END(ApiController)  ///< End Codegen

#endif  // BLACKJACKCONTROLLER_HPP_INCLUDED
