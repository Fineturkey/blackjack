/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */

#include "gtest/gtest.h"
#include "model/Card.hpp"
#include "model/Dealer.hpp"
#include "model/Deck.hpp"
#include "model/Player.hpp"

TEST(TestDealer, ConstructorTest) {
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);
  delete dealer;
}

TEST(TestDealer, DestructorTest) {
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);
  delete dealer;
}

TEST(TestDealer, AddCardTest) {
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);

  dealer->addCard(deck->drawCard());

  EXPECT_EQ(dealer->getHandSize(), 1);

  delete dealer;
}

TEST(TestDealer, TestDeal) {
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);
  Player* player = new Player("BOB");
  std::vector<Player*> players;
  players.push_back(player);

  dealer->deal(players);

  EXPECT_EQ(dealer->getHandSize(), 2);
  EXPECT_EQ(player->getHandSize(), 2);

  delete dealer;
  delete player;
}

TEST(TestDealer, checkStatus) {
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);

  dealer->addCard(deck->drawCard());

  EXPECT_GT(dealer->checkStatus(), 0);

  delete dealer;
}

TEST(TestDealer, checkStatusACE) {
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);

  dealer->addCard(new Card(Card::Suit::SPADES, Card::Rank::ACE));

  EXPECT_EQ(dealer->checkStatus(), 11);

  dealer->addCard(new Card(Card::Suit::SPADES, Card::Rank::NINE));

  EXPECT_EQ(dealer->checkStatus(), 20);

  dealer->addCard(new Card(Card::Suit::SPADES, Card::Rank::KING));

  EXPECT_EQ(dealer->checkStatus(), 20);

  delete dealer;
}

TEST(TestDealer, TestGetHandSize) {
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);

  dealer->addCard(deck->drawCard());

  EXPECT_EQ(dealer->getHandSize(), 1);

  delete dealer;
}

TEST(TestDealer, TestClearHand) {
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);

  dealer->addCard(deck->drawCard());
  dealer->clearDealerHand();
  EXPECT_EQ(dealer->getHandSize(), 0);
  delete dealer;
}
