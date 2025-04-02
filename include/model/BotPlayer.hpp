/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @date Spring 2025
 */

#ifndef BOTPLAYER_HPP_INCLUDED
#define BOTPLAYER_HPP_INCLUDED

#include <string>
#include <vector>

#include "../../include/model/Card.hpp"
#include "../../include/model/Deck.hpp"
#include "../../include/model/Player.hpp"

/**
 * @class BotPlayer BotPlayer.hpp "BotPlayer.hpp"
 * @brief A class to represent a bot opponent in blackjack.
 */

class BotPlayer : public Player {
 public:
  /**
   * @brief Constructor for bot player.
   */
  BotPlayer();
  /**
   * @brief Destructor for bot player.
   */
  ~BotPlayer() = default;
  /**
   * @brief Provides the playing logic of the bot player during the game.
   * @return int The total value of the bot player's hand.
   */
  int checkStatus();
  /**
   * @brief Draws a card from the deck and adds it to the bot player's hand.
   * @param deck The deck to draw a card from.
   */
  void hit(Deck* deck) override;
};

#endif
