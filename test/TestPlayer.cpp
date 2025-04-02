/**
 * @date Spring 2025
 */
#include "gtest/gtest.h"
#include "model/Card.hpp"
#include "model/Deck.hpp"
#include "model/Player.hpp"

TEST(TestPlayer, ConstructorTest) {
  Player* player = new Player("Denji");
  delete player;
}

TEST(TestPlayer, getNameTest) {
  Player* player = new Player("Lance");
  EXPECT_EQ(player->getName(), "Lance");
  delete player;
}

TEST(TestPlayer, isBustedTest) {
  Player* player = new Player("Lance");
  Deck* d = new Deck();
  player->hit(d);
  EXPECT_FALSE(player->isBusted());
  delete player;
  delete d;
}

TEST(TestPlayer, addCardTest) {
  Player* player = new Player("Lance");
  Card* c = new Card(Card::Suit::SPADES, Card::Rank::ACE);
  player->addCard(c);
  EXPECT_EQ(player->getHand().size(), 1);
  player->clearHand();
  delete player;
}

TEST(TestPlayer, clearHandTest) {
  Player* player = new Player("Lance");
  Card* c = new Card(Card::Suit::SPADES, Card::Rank::ACE);
  player->addCard(c);
  EXPECT_EQ(player->getHand().size(), 1);
  player->clearHand();
  EXPECT_EQ(player->getHand().size(), 0);
  delete player;
}

TEST(TestPlayer, getHandTest) {
  Player* player = new Player("Isagi");
  Card* c1 = new Card(Card::Suit::SPADES, Card::Rank::TWO);
  Card* c2 = new Card(Card::Suit::SPADES, Card::Rank::THREE);
  player->addCard(c1);
  player->addCard(c2);
  std::vector<Card*> hand = player->getHand();
  EXPECT_EQ(hand.size(), 2);
  player->clearHand();
  delete player;
}

TEST(TestPlayer, getHandValueTest) {
  Player* player = new Player("Isagi");
  Card* c1 = new Card(Card::Suit::SPADES, Card::Rank::TWO);
  Card* c2 = new Card(Card::Suit::SPADES, Card::Rank::THREE);
  player->addCard(c1);
  player->addCard(c2);
  EXPECT_EQ(player->getHandValue(), 5);
  player->clearHand();
  Card* c3 = new Card(Card::Suit::SPADES, Card::Rank::ACE);
  Card* c4 = new Card(Card::Suit::SPADES, Card::Rank::NINE);
  player->addCard(c3);
  player->addCard(c4);
  EXPECT_EQ(player->getHandValue(), 20);
  Card* c5 = new Card(Card::Suit::SPADES, Card::Rank::KING);
  player->addCard(c5);
  EXPECT_EQ(player->getHandValue(), 20);
  player->clearHand();
  delete player;
}

TEST(TestPlayer, standTest) {
  Player* player = new Player("Isagi");
  player->stand();
  EXPECT_EQ(player->getHand().size(), 0);
  delete player;
}

TEST(TestPlayer, hitTest) {
  Player* player = new Player("Isagi");
  Deck* d = new Deck();
  EXPECT_EQ(player->getHand().size(), 0);
  player->hit(d);
  EXPECT_EQ(player->getHand().size(), 1);
  delete player;
  delete d;
}
