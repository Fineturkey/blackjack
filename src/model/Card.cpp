/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/model/Card.hpp"

#include <string>

Card::~Card() {}

Card::Suit Card::getSuit() { return suit; }

Card::Rank Card::getRank() { return rank; }

int Card::getRankValue(Card::Rank rank) {
  switch (rank) {
    case ACE:
      return 1;
    case TWO:
      return 2;
    case THREE:
      return 3;
    case FOUR:
      return 4;
    case FIVE:
      return 5;
    case SIX:
      return 6;
    case SEVEN:
      return 7;
    case EIGHT:
      return 8;
    case NINE:
      return 9;
    case TEN:
      return 10;
    case JACK:
      return 10;
    case QUEEN:
      return 10;
    case KING:
      return 10;
  }
}

int Card::getSuitValue(Card::Suit suit) {
  switch (suit) {
    case HEARTS:
      return 0;
    case DIAMONDS:
      return 1;
    case CLUBS:
      return 2;
    case SPADES:
      return 3;
  }
}

std::string Card::getSuitString() {
  switch (suit) {
    case HEARTS: return "Hearts";
    case DIAMONDS: return "Diamonds";
    case CLUBS: return "Clubs";
    case SPADES: return "Spades";
    default: return "";
  }
}

std::string Card::getRankString() {
  switch (rank) {
    case ACE: return "Ace";
    case TWO: return "2";
    case THREE: return "3";
    case FOUR: return "4";
    case FIVE: return "5";
    case SIX: return "6";
    case SEVEN: return "7";
    case EIGHT: return "8";
    case NINE: return "9";
    case TEN: return "10";
    case JACK: return "Jack";
    case QUEEN: return "Queen";
    case KING: return "King";
    default: return "";
  }
}

Card::Suit Card::stringToSuit(const std::string& suit) {
  if (suit == "Hearts") return HEARTS;
  if (suit == "Diamonds") return DIAMONDS;
  if (suit == "Clubs") return CLUBS;
  if (suit == "Spades") return SPADES;
  throw std::invalid_argument("Invalid suit");
}

Card::Rank Card::stringToRank(const std::string& rank) {
  if (rank == "Ace") return ACE;
  if (rank == "2") return TWO;
  if (rank == "3") return THREE;
  if (rank == "4") return FOUR;
  if (rank == "5") return FIVE;
  if (rank == "6") return SIX;
  if (rank == "7") return SEVEN;
  if (rank == "8") return EIGHT;
  if (rank == "9") return NINE;
  if (rank == "10") return TEN;
  if (rank == "Jack") return JACK;
  if (rank == "Queen") return QUEEN;
  if (rank == "King") return KING;
  throw std::invalid_argument("Invalid rank");
}
