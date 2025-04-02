/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <iostream>
#include <vector>

#include "../../include/model/Card.hpp"

/**
 * @class Deck Deck.hpp "Deck.hpp"
 * @brief A class that defines the Deck of cards object.
 */
class Deck {
 public:
  /**
   * @brief Constructs the deck by pushing back each card into a vector in
   * order.
   */
  Deck();

  /**
   * @brief deletes each card in the deck.
   */
  virtual ~Deck();

  /**
   * @brief shuffles the deck.
   */
  void shuffle();

  /**
   * @brief Adds disposed of cards back into the deck when necessary.
   * @param[in] Card that is getting put back into deck.
   */
  void addCard(Card* c);

  /**
   * @brief removes a card from the deck.
   * @param[in] Card being removed from deck.
   */
  void removeCard(Card* c);

  /**
   * @brief draws a card from the top of the deck.
   * @return A card from the top of the deck.
   */
  Card* drawCard();

  /**
   * @brief the current number of cards in the deck.
   * @return number of cards in deck.
   */
  int getNumCards();

  /**
   * @brief A method to get the current deck.
   * @return A vector of cards, the deck.
   */
  std::vector<Card*> getDeck();

 private:
  std::vector<Card*> deck;
};

#endif  // DECK_HPP_INCLUDED
