/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */

#include <vector>

#include "Card.hpp"
#include "CardUI.hpp"
#include "GameUI.hpp"
#include "Player.hpp"
#include "PlayerView.hpp"
#include "gtest/gtest.h"

TEST(TestGameUI, TestConstructor) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  delete gameUI;
}

TEST(TestGameUI, TestDestructor) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  delete gameUI;
}

TEST(TestGameUI, TestDisplayGameName) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->displayGameName();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Welcome to Blackjack!\n");
  delete gameUI;
}

TEST(TestGameUI, TestDisplayHandStatus) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  Player* player = new Player("BOB");
  player->addCard(new Card(Card::Suit::SPADES, Card::Rank::ACE));
  player->addCard(new Card(Card::Suit::DIAMONDS, Card::Rank::TWO));
  testing::internal::CaptureStdout();
  gameUI->displayHandStatus(player->getHand(), 13, player);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(
      output,
      "BOB, your hand is: [Ace of Spades], [Two of Diamonds], Value: 13\n");
  delete gameUI;
  delete player;
}

TEST(TestGameUI, TestPromptUserAction) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->promptUserAction();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Do you want to hit (h) or stand (s)? ");
  delete gameUI;
}

TEST(TestGameUI, TestBustMessage) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->bustMessage();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "You busted!\n");
  delete gameUI;
}

TEST(TestGameUI, TestInvalidInput) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->invalidInput();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Invalid input. Please enter the correct input.\n");
  delete gameUI;
}

TEST(TestGameUI, TestDealerValue) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->dealerValue(13);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Dealer's hand value: 13\n");
  delete gameUI;
}

TEST(TestGameUI, TestBust) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  Player* player = new Player("BOB");
  testing::internal::CaptureStdout();
  gameUI->bust(player);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "BOB busted!\n");
  delete gameUI;
  delete player;
}

TEST(TestGameUI, TestWin) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  Player* player = new Player("BOB");
  testing::internal::CaptureStdout();
  gameUI->win(player);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "BOB wins!\n");
  delete gameUI;
  delete player;
}

TEST(TestGameUI, TestLoses) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  Player* player = new Player("BOB");
  testing::internal::CaptureStdout();
  gameUI->loses(player);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "BOB loses!\n");
  delete gameUI;
  delete player;
}

TEST(TestGameUI, TestPush) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  Player* player = new Player("BOB");
  testing::internal::CaptureStdout();
  gameUI->push(player);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "BOB pushes!\n");
  delete gameUI;
  delete player;
}

TEST(TestGameUI, TestPlayAgain) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->playAgain();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Do you want to play again? (y/n): ");
  delete gameUI;
}

TEST(TestGameUI, TestNewCard) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->newCard();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "You drew a card! ");
  delete gameUI;
}

TEST(TestGameUI, TestGetNumPlayers) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->getNumPlayers();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Enter the number of players: ");
  delete gameUI;
}

TEST(TestGameUI, TestGetPlayerNames) {
  CardUI* cardUI = new CardUI();
  PlayerView* pv = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(pv);
  testing::internal::CaptureStdout();
  gameUI->getPlayerNames(2);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Enter the name of each player: \nPlayer 1: Player 2: ");
  delete gameUI;
}
