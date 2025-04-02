/**
 * @author Eugene Gu <e.gu@uleth.ca>, Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 * @brief Defines the Game class, which controls the flow of the Blackjack game.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "../../include/model/Dealer.hpp"
#include "../../include/model/Deck.hpp"
#include "../../include/model/Player.hpp"
#include "../../include/view/GameUI.hpp"

/**
 * @class Game
 * @brief Manages the game flow, including player and dealer turns.
 */
class Game {
 public:
  /**
   * @brief Constructs a Game instance.
   * @param gameUI Reference of GameUI.
   * @param dealer Reference of Dealer.
   */
  Game(GameUI* gameUI, Dealer* dealer);
  /**
   * @brief Destroys the Game instance and deallocates memory.
   */
  ~Game();
  /**
   * @brief Starts the game.
   */
  void start();
  /**
   * @brief Initialize players
   */
  void playerInit();
  /**
   * @brief Handles the player's turn (hit or stand).
   */
  void playerTurn();
  /**
   * @brief Handles the dealer's turn logic.
   */
  void dealerTurn();
  /**
   * @brief Determines the winner at the end of a round.
   * @return True if the player wins, loses, pushes, returns false otherwise.
   */
  bool checkWinner();
  /**
   * @brief Adds a player to the game.
   * @param p The player to add.
   */
  void addPlayer(Player* p);

  /**
   * @brief Gets a vector of current players.
   * @return A vector of Player pointers.
   */
  const std::vector<Player*>& getPlayers() const;

  /**
   * @brief Gets a player by name.
   * @param name The name of the player to get.
   * @return A pointer to the player with the given name, or nullptr if not
   * found.
   */
  Player* getPlayerByName(const std::string& name);

  /**
   * @brief Deals two cards to each player and the dealer.
   */
  void deal();

 private:
  GameUI* gameUI;
  Dealer* dealer;
  std::vector<Player*> players;
};
#endif  // GAME_HPP
