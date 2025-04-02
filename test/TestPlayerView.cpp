/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */

#include <vector>

#include "Card.hpp"
#include "CardUI.hpp"
#include "Player.hpp"
#include "PlayerView.hpp"
#include "gtest/gtest.h"

TEST(PlayerView, displayHandTest) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  Player* player = new Player("BOB");

  std::vector<Card*> hand;
  Card* c1 = new Card(Card::Suit::SPADES, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::DIAMONDS, Card::Rank::TWO);
  hand.push_back(c1);
  hand.push_back(c2);
  testing::internal::CaptureStdout();
  pv->displayHand(hand, 13, player);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(
      output,
      "BOB, your hand is: [Ace of Spades], [Two of Diamonds], Value: 13\n");
  delete c1;
  delete c2;
  delete pv;
  delete player;
}

TEST(PlayerView, promptUserActionTest) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  Player* player = new Player("BOB");
  testing::internal::CaptureStdout();
  pv->promptUserAction();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Do you want to hit (h) or stand (s)? ");
  delete pv;
  delete player;
}

TEST(PlayerView, displayBustMessageTest) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  Player* player = new Player("BOB");
  testing::internal::CaptureStdout();
  pv->displayBustMessage();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "You busted!\n");
  delete pv;
  delete player;
}

TEST(PlayerView, displayInvalidInputTest) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  Player* player = new Player("BOB");
  testing::internal::CaptureStdout();
  pv->displayInvalidInput();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Invalid input. Please enter the correct input.\n");
  delete pv;
  delete player;
}
