/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @date Spring 2025
 */
#include "gtest/gtest.h"
#include "model/BotPlayer.hpp"
#include "model/Deck.hpp"

TEST(BotPlayer, checkStatus) {
  BotPlayer* bot = new BotPlayer();
  EXPECT_EQ(bot->checkStatus(), 0);
  bot->addCard(new Card(Card::Suit::SPADES, Card::Rank::ACE));
  EXPECT_EQ(bot->checkStatus(), 11);
  bot->addCard(new Card(Card::Suit::SPADES, Card::Rank::KING));
  EXPECT_EQ(bot->checkStatus(), 21);
  bot->addCard(new Card(Card::Suit::SPADES, Card::Rank::QUEEN));
  EXPECT_EQ(bot->checkStatus(), 21);

  delete bot;
}

TEST(BotPlayer, hit) {
  BotPlayer* bot = new BotPlayer();
  Deck* deck = new Deck();
  bot->hit(deck);
  EXPECT_EQ(bot->getHand().size(), 1);

  delete bot;
  delete deck;
}
