/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#ifndef GAMEUI_INCLUDED
#define GAMEUI_INCLUDED

#include <string>
#include <vector>

#include "../../include/view/PlayerView.hpp"

/**
 * @class GameUI GameUI.hpp "GameUI.hpp"
 * @brief Controls all UI of game.
 */
class GameUI {
 public:
  /**
   * @brief Creates a GameUI object.
   * @param UI A pointer to a PlayerView object.
   */
  GameUI(PlayerView* UI);

  /**
   * @brief Deletes the PlayerView object.
   */
  virtual ~GameUI();

  /**
   * @brief Displays the name of the game.
   */
  void displayGameName();

  /**
   * @brief Displays the dealer's first card.
   * @param dealer The dealer.
   * @param hand The dealer's hand.
   */
  void displayDealersCard(std::vector<Card*> hand, Dealer* dealer);

  /**
   * @brief Displays the dealer's hand.
   * @param hand The dealer's hand.
   * @param dealer The dealer.
   */
  void displayDealerHand(std::vector<Card*> hand, Dealer* dealer);

  /**
   * @brief Displays the player's hand and the value of the hand.
   * @param hand The player's hand.
   * @param handValue The value of the player's hand.
   * @param p The player.
   */
  void displayHandStatus(const std::vector<Card*> hand, int handValue,
                         const Player* p);

  /**
   * @brief Prompts the player for an action.
   * @return User choice.
   */
  char promptUserAction();

  /**
   * @brief Displays a message indicating that the player busted.
   */
  void bustMessage();

  /**
   * @brief Displays a message indicating that the player entered an invalid
   * input.
   */
  void invalidInput();

  /**
   * @brief Displays the value of the dealer's hand.
   * @param dealerValue The value of the dealer's hand.
   */
  void dealerValue(int dealerValue);

  /**
   * @brief Prompts the player to play again.
   * @return User choice.
   */
  char playAgain();

  /**
   * @brief Displays a message indicating that the player won.
   * @param p The player.
   */
  void bust(Player* p);

  /**
   * @brief Displays a message indicating that the player lost.
   * @param p The player.
   */
  void win(Player* p);

  /**
   * @brief Displays a message indicating that the player lost.
   * @param p The player.
   */
  void loses(Player* p);

  /**
   * @brief Displays a message indicating that the player pushed.
   * @param p The player.
   */
  void push(Player* p);

  /**
   * @brief Displays a message indicating that the player got a new card.
   */
  void newCard();

  /**
   * @brief Asks the user how many player are playing.
   * @return The number of players.
   */
  int getNumPlayers();

  /**
   * @brief Asks the user for the name of the player.
   * @param numPlayers The number of players.
   * @return The name of the player.
   */
  std::vector<std::string> getPlayerNames(int numPlayers);

 private:
  PlayerView* playerUI;
};

#endif  // GAMEUI_INCLUDED
