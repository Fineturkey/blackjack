/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */

#include "gtest/gtest.h"
#include "model/Card.hpp"
#include "model/Dealer.hpp"
#include "model/Deck.hpp"

TEST(TestCard, ConstructorTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::ACE);
  delete card;
}

TEST(TestCard, DestructorTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::ACE);
  delete card;
}

TEST(TestCard, GetSpadeTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::ACE);

  EXPECT_EQ(card->getSuit(), Card::Suit::SPADES);
  delete card;
}

TEST(TestCard, GetHeartTest) {
  Card* card = new Card(Card::Suit::HEARTS, Card::Rank::ACE);

  EXPECT_EQ(card->getSuit(), Card::Suit::HEARTS);
  delete card;
}

TEST(TestCard, GetDiamondTest) {
  Card* card = new Card(Card::Suit::DIAMONDS, Card::Rank::ACE);

  EXPECT_EQ(card->getSuit(), Card::Suit::DIAMONDS);
  delete card;
}

TEST(TestCard, GetClubTest) {
  Card* card = new Card(Card::Suit::CLUBS, Card::Rank::ACE);

  EXPECT_EQ(card->getSuit(), Card::Suit::CLUBS);
  delete card;
}

TEST(TestCard, GetAceTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::ACE);

  EXPECT_EQ(card->getRank(), Card::Rank::ACE);
  delete card;
}

TEST(TestCard, GetTwoTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::TWO);

  EXPECT_EQ(card->getRank(), Card::Rank::TWO);
  delete card;
}

TEST(TestCard, GetThreeTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::THREE);

  EXPECT_EQ(card->getRank(), Card::Rank::THREE);
  delete card;
}

TEST(TestCard, GetFourTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::FOUR);

  EXPECT_EQ(card->getRank(), Card::Rank::FOUR);
  delete card;
}

TEST(TestCard, GetFiveTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::FIVE);

  EXPECT_EQ(card->getRank(), Card::Rank::FIVE);
  delete card;
}

TEST(TestCard, GetSixTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::SIX);

  EXPECT_EQ(card->getRank(), Card::Rank::SIX);
  delete card;
}

TEST(TestCard, GetSevenTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::SEVEN);

  EXPECT_EQ(card->getRank(), Card::Rank::SEVEN);
  delete card;
}

TEST(TestCard, GetEightTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::EIGHT);

  EXPECT_EQ(card->getRank(), Card::Rank::EIGHT);
  delete card;
}

TEST(TestCard, GetNineTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::NINE);

  EXPECT_EQ(card->getRank(), Card::Rank::NINE);
  delete card;
}

TEST(TestCard, GetTenTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::TEN);

  EXPECT_EQ(card->getRank(), Card::Rank::TEN);
  delete card;
}

TEST(TestCard, GetJackTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::JACK);

  EXPECT_EQ(card->getRank(), Card::Rank::JACK);
  delete card;
}

TEST(TestCard, GetQueenTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::QUEEN);

  EXPECT_EQ(card->getRank(), Card::Rank::QUEEN);
  delete card;
}

TEST(TestCard, GetKingTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::KING);

  EXPECT_EQ(card->getRank(), Card::Rank::KING);
  delete card;
}

TEST(TestCard, GetAceValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::ACE);

  EXPECT_EQ(card->getRankValue(card->getRank()), 1);

  delete card;
}

TEST(TestCard, GetTwoValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::TWO);

  EXPECT_EQ(card->getRankValue(card->getRank()), 2);

  delete card;
}

TEST(TestCard, GetThreeValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::THREE);

  EXPECT_EQ(card->getRankValue(card->getRank()), 3);

  delete card;
}

TEST(TestCard, GetFourValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::FOUR);

  EXPECT_EQ(card->getRankValue(card->getRank()), 4);

  delete card;
}

TEST(TestCard, GetFiveValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::FIVE);

  EXPECT_EQ(card->getRankValue(card->getRank()), 5);

  delete card;
}

TEST(TestCard, GetSixValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::SIX);

  EXPECT_EQ(card->getRankValue(card->getRank()), 6);

  delete card;
}

TEST(TestCard, GetSevenValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::SEVEN);

  EXPECT_EQ(card->getRankValue(card->getRank()), 7);

  delete card;
}

TEST(TestCard, GetEightValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::EIGHT);

  EXPECT_EQ(card->getRankValue(card->getRank()), 8);

  delete card;
}

TEST(TestCard, GetNineValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::NINE);

  EXPECT_EQ(card->getRankValue(card->getRank()), 9);

  delete card;
}

TEST(TestCard, GetTenValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::TEN);

  EXPECT_EQ(card->getRankValue(card->getRank()), 10);

  delete card;
}

TEST(TestCard, GetJackValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::JACK);

  EXPECT_EQ(card->getRankValue(card->getRank()), 10);

  delete card;
}

TEST(TestCard, GetQueenValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::QUEEN);

  EXPECT_EQ(card->getRankValue(card->getRank()), 10);

  delete card;
}

TEST(TestCard, GetKingValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::KING);

  EXPECT_EQ(card->getRankValue(card->getRank()), 10);

  delete card;
}

TEST(TestCard, GetSpadeValueTest) {
  Card* card = new Card(Card::Suit::SPADES, Card::Rank::KING);

  EXPECT_EQ(card->getSuitValue(card->getSuit()), 3);

  delete card;
}
