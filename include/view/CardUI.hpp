/**
 * @author Austin Savoie <austin.savoie@uleth.ca>abort
 * @date Spring 2025
 */
#ifndef CARDUI_HPP_INCLUDED
#define CARDUI_HPP_INCLUDED

#include <iostream>
#include <string>

#include "../../include/model/Card.hpp"

/**
 * @class CardUI CardUI.hpp "CardUI.hpp"
 * @brief The implementation of the CardUI to adhere to MVC.
 */
class CardUI {
 public:
  /**
   * @brief Constructor that builds a cardUI based on suit and rank.
   */
  CardUI();

  /**
   * @brief Destructor for the cardUI.
   */
  virtual ~CardUI();

  /**
   * @brief Outputs the cards suit
   * @param s The suit of the card.
   * @return The suit of the card.
   */
  std::string displaySuit(Card::Suit s);

  /**
   * @brief Outputs the cards rank
   * @param r The rank of the card.
   * @return The rank of the card.
   */
  std::string displayRank(Card::Rank r);
};

#endif  // CARDUI_HPP_INCLUDED
