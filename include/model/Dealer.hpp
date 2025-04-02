/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#ifndef DEALER_HPP_INCLUDED
#define DEALER_HPP_INCLUDED

#include <vector>

#include "../../include/model/Deck.hpp"
#include "../../include/model/Player.hpp"

/**
 * @class Dealer Dealer.hpp "Dealer.hpp"
 * @brief Contains logic for dealing cards to the player, as well as the dealers
 * plays.
 */
class Dealer {
 public:
  /**
   * @brief Dealer constructor that uses dependency injection to use the deck of
   * cards.
   * @param[in] Deck pointer.
   */
  Dealer(Deck* d) : deck(d) {}

  /**
   * @brief Dealer Destructor. Deletes the deck the dealer is currently using
   * and its hand.
   */
  virtual ~Dealer();

  /**
   * @brief Adds a card to the dealers hand.
   * @param[in] The card the dealer adds to his hand.
   */
  void addCard(Card* c);

  /**
   * @brief Deals two cards to each member of the table.
   * @param[in] A vector of player pointers.
   */
  void deal(std::vector<Player*> players);

  /**
   * @brief Deals a singular card if a player hits.
   * @return A card pointer.
   */
  Card* dealSingleCard();
  /**
   * @brief Checks the dealers current hand and based on the value.
   * @return integer value of the hand.
   */
  int checkStatus();

  /**
   * @brief gets the size of the hand.
   * @returns integer size of the hand.
   */
  int getHandSize();

  /**
   * @brief clears the hand of the dealer
   * @returns an empty vector, in order to reset the hand
   */
  void clearDealerHand();

  /**
   * @brief gets the dealers hand.
   * @returns a vector of cards.
   */
  std::vector<Card*> getHand();

  /**
   * @brief Gets hand value.
   * @return integer value of the hand.
   */
  int getCardValue(Card* c);

 private:
  Deck* deck;
  std::vector<Card*> hand;
};

#endif  // DEALER_HPP_INCLUDED
