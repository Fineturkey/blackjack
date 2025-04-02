/**
 * @author Austin Savoie <austin.savoie@uleth.ca>abs
 * @date Spring 2025
 */
#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

#include <iostream>
#include <string>

/**
 * @class Card Card.hpp "Card.hpp"
 * @brief The implementation of a singular card object.
 */
class Card {
 public:
  enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
  enum Rank {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
  };

  /**
   * @brief Constructor that build a card based on suit and rank.
   * @param[in] Suit, Rank the suit and rank of the card.
   */
  Card(Card::Suit s, Card::Rank r) : suit(s), rank(r) {}

  /**
   * @brief card destructor.
   */
  virtual ~Card();

  /**
   * @brief gets the suit of the specific card.
   * @return Suit of the card
   */
  Suit getSuit();

  /**
   * @brief gets the rank of the card.
   * @return Rank of the card.
   */
  Rank getRank();

  /**
   * @brief Converts the rank to an integer for easier manipulation.
   * @param[in] Rank of card
   * @return integer value of the cards rank.
   */
  int getRankValue(Card::Rank rank);

  /**
   * @brief Converts the suit to an integer for easier manipulation.
   * @param[in] Suit of card.
   * @return Integer value of the cards suit.
   */
  int getSuitValue(Card::Suit suit);

  /**
   * @brief Converts the suit to a string.
   * @return String representation of the suit.
   */
  std::string getSuitString();

  /**
   * @brief Converts the rank to a string.
   * @return String representation of the rank.
   */
  std::string getRankString();

  /**
   * @brief Converts a string to a Suit enum.
   * @param[in] suit String representation of the suit.
   * @return Suit enum.
   */
  static Suit stringToSuit(const std::string& suit);

    /**
   * @brief Converts a string to a Rank enum.
   * @param[in] rank String representation of the rank.
   * @return Rank enum.
   */
  static Rank stringToRank(const std::string& rank);

 private:
  Suit suit;
  Rank rank;
};

#endif  // CARD_HPP_INCLUDED
