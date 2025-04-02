/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @author Sofiah Plarisan <s.plarisan@uleth.ca>
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <string>
#include <vector>

#include "../../include/model/Card.hpp"
#include "../../include/model/Deck.hpp"

/**
 * @class Player Player.hpp "Player.hpp"
 * @brief A class to represent a player in blackjack.
 */

class Player {
 public:
  /**
   * @brief Creates a Player object.
   * @param name The player's name.
   */
  Player(std::string name);

  /**
   * @brief Deletes the Player object.
   */
  virtual ~Player();

  /**
   * @brief Gets the player's name.
   * @return The player's name.
   */
  std::string getName() const;

  /**
   * @brief Determines if the player's hand value is over 21.
   * @return True if the player's hand value is over 21, false otherwise.
   */
  bool isBusted() const;

  /**
   * @brief Adds a card to the player's hand.
   * @param card The card to add to the player's hand.
   */
  void addCard(Card* card);

  /**
   * @brief Clears the player's hand.
   */
  void clearHand();

  /**
   * @brief Gets the player's hand
   * @return The player's hand.
   */
  std::vector<Card*> getHand();

  /**
   * @brief Gets the player's hand size.
   * @return The player's hand size.
   */
  int getHandSize();

  /**
   * @brief Gets the player's hand value.
   * @return The player's hand value.
   */
  int getHandValue() const;

  /**
   * @brief Determines if the player's hand value is 21.
   * @return True if the player's hand value is 21, false otherwise.
   */
  void stand();

  /**
   * @brief Determines if the player wants to hit or stand.
   * @param deck The deck of cards.
   */
  virtual void hit(Deck* deck);

  /**
   * @brief Gets player based on name.
   * @param name The player's name.
   * @return The player.
   */
  Player* getPlayerByName(std::string name);

 protected:
  std::string name;
  std::vector<Card*> hand;

 private:
  const int BUSTLIMIT = 21;
};

#endif
