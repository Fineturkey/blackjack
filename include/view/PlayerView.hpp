/**
 * @author Sofiah Plarisan <s.plarisan@uleth.ca>
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#ifndef PLAYERVIEW_HPP
#define PLAYERVIEW_HPP

#include <vector>

#include "../../include/model/Card.hpp"
#include "../../include/model/Dealer.hpp"
#include "../../include/model/Player.hpp"
#include "../../include/view/CardUI.hpp"

/**
 * @class PlayerView Playerview.hpp "PlayerView.hpp
 * @brief Displays the player's hand and prompts the player for an action."
 */
class PlayerView {
 public:
  /**
   * @brief Creates a PlayerView object.
   * @param CUI A pointer to a CardUI object.
   */
  PlayerView(CardUI* CUI) : cardUI(CUI) {}

  /**
   * @brief Deletes the CardUI object.
   */
  virtual ~PlayerView();

  /**
   * @brief Displays the player's hand and the value of the hand.
   * @param hand The player's hand.
   * @param handValue The value of the player's hand.
   */
  void displayHand(const std::vector<Card*> hand, int handValue,
                   const Player* p);

  /**
   * @brief Displays the dealer's first card.
   * @param d The dealer.
   * @param hand The dealer's hand.
   */
  void displayDealersFirstCard(Dealer* d, std::vector<Card*> hand);

  /**
   * @brief Displays the dealer's hand.
   * @param d The dealer.
   * @param hand The dealer's hand.
   */
  void displayDealersHand(Dealer* d, std::vector<Card*> hand);
  /**
   * @brief Prompts the player for an action.
   * @return User choice.
   */
  char promptUserAction();

  /**
   * @brief Displays a message indicating that the player busted.
   */
  void displayBustMessage();

  /**
   * @brief Displays a message indicating that the player entered an invalid
   * input.
   */
  void displayInvalidInput();

 private:
  CardUI* cardUI;
};

#endif
