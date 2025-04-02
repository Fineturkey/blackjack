/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */

#include "gtest/gtest.h"
#include "model/Dealer.hpp"
#include "model/Deck.hpp"
#include "model/Card.hpp"

TEST(TestDeck, ConstructorTest) {
  Deck* deck = new Deck();
  delete deck;
}

TEST(TestDeck, DestructorTest) {
  Deck* deck = new Deck();
  delete deck;
}

TEST(TestDeck, ShuffleTest) {
  Deck* deck = new Deck();

  deck->shuffle();

  delete deck;
}

TEST(TestDeck, AddCardTest) {
  Deck* deck = new Deck();
  int s = 0;
  int r = 0;
  Card* card = new Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r));

  deck->addCard(card);
  EXPECT_EQ(deck->getNumCards(), 53);

  delete deck;
}

TEST(TestDeck, RemoveCardTest) {
  Deck* deck = new Deck();
  int s = 0;
  int r = 0;
  Card* card = new Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r));

  deck->addCard(card);
  EXPECT_EQ(deck->getNumCards(), 53);

  deck->removeCard(card);
  EXPECT_EQ(deck->getNumCards(), 52);

  delete deck;
  delete card;
}

TEST(TestDeck, DrawCardTest) {
  Deck* deck = new Deck();

  Card* card = deck->drawCard();

  EXPECT_EQ(deck->getNumCards(), 51);

  delete card;
  delete deck;
}

TEST(TestDeck, GetNumCardsTest) {
  Deck* deck = new Deck();

  EXPECT_EQ(deck->getNumCards(), 52);

  delete deck;
}
