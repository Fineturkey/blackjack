/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */

#include "gtest/gtest.h"
#include "model/Card.hpp"
#include "view/CardUI.hpp"

TEST(TestCardUI, ConstructorTest) {
  CardUI* card = new CardUI();
  delete card;
}

TEST(TestCardUI, DestructorTest) {
  CardUI* card = new CardUI();
  delete card;
}

TEST(TestCardUI, DisplayHeartTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::ACE);
  card->displaySuit(c.getSuit());
  EXPECT_EQ(c.getSuitValue(c.getSuit()), 0);
  delete card;
}

TEST(TestCardUI, DisplayDiamondTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::DIAMONDS, Card::Rank::ACE);
  card->displaySuit(c.getSuit());
  EXPECT_EQ(c.getSuitValue(c.getSuit()), 1);
  delete card;
}

TEST(TestCardUI, DisplayClubTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::CLUBS, Card::Rank::ACE);
  card->displaySuit(c.getSuit());
  EXPECT_EQ(c.getSuitValue(c.getSuit()), 2);
  delete card;
}

TEST(TestCardUI, DisplaySpadeTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::SPADES, Card::Rank::ACE);
  card->displaySuit(c.getSuit());
  EXPECT_EQ(c.getSuitValue(c.getSuit()), 3);
  delete card;
}

TEST(TestCardUI, DisplayAceTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::ACE);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 1);
  delete card;
}

TEST(TestCardUI, DisplayTwoTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::TWO);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 2);
  delete card;
}

TEST(TestCardUI, DisplayThreeTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::THREE);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 3);
  delete card;
}

TEST(TestCardUI, DisplayFourTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::FOUR);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 4);
  delete card;
}

TEST(TestCardUI, DisplayFiveTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::FIVE);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 5);
  delete card;
}

TEST(TestCardUI, DisplaySixTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::SIX);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 6);
  delete card;
}

TEST(TestCardUI, DisplaySevenTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::SEVEN);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 7);
  delete card;
}

TEST(TestCardUI, DisplayEightTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::EIGHT);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 8);
  delete card;
}

TEST(TestCardUI, DisplayNineTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::NINE);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 9);
  delete card;
}

TEST(TestCardUI, DisplayTenTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::TEN);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 10);
  delete card;
}

TEST(TestCardUI, DisplayJackTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::JACK);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 10);
  delete card;
}

TEST(TestCardUI, DisplayQueenTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::QUEEN);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 10);
  delete card;
}

TEST(TestCardUI, DisplayKingTest) {
  CardUI* card = new CardUI();
  Card c = Card(Card::Suit::HEARTS, Card::Rank::KING);
  card->displayRank(c.getRank());
  EXPECT_EQ(c.getRankValue(c.getRank()), 10);
  delete card;
}
