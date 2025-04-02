/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/view/CardUI.hpp"

#include <iostream>

#include "../../include/model/Card.hpp"

CardUI::CardUI() {}

CardUI::~CardUI() {}

std::string CardUI::displaySuit(Card::Suit s) {
  switch (s) {
    case Card::CLUBS:
      return "Clubs";
      break;
    case Card::DIAMONDS:
      return "Diamonds";
      break;
    case Card::HEARTS:
      return "Hearts";
      break;
    case Card::SPADES:
      return "Spades";
      break;
  }
}

std::string CardUI::displayRank(Card::Rank r) {
  switch (r) {
    case Card::ACE:
      return "Ace";
      break;
    case Card::TWO:
      return "Two";
      break;
    case Card::THREE:
      return "Three";
      break;
    case Card::FOUR:
      return "Four";
      break;
    case Card::FIVE:
      return "Five";
      break;
    case Card::SIX:
      return "Six";
      break;
    case Card::SEVEN:
      return "Seven";
      break;
    case Card::EIGHT:
      return "Eight";
      break;
    case Card::NINE:
      return "Nine";
      break;
    case Card::TEN:
      return "Ten";
      break;
    case Card::JACK:
      return "Jack";
      break;
    case Card::QUEEN:
      return "Queen";
      break;
    case Card::KING:
      return "King";
      break;
  }
}
