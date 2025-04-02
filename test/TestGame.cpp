#include <sstream>

#include "Game.hpp"
#include "MockClasses.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::_;
using ::testing::InSequence;
using ::testing::Return;

/*
TEST(TestGame, TestStart) {
  MockCardUI mockCardUI;
  MockPlayerView mockPlayerView(&mockCardUI);
  MockGameUI mockGameUI(&mockPlayerView);

  std::string userInput = "s";

  Game game(&mockGameUI);

  EXPECT_CALL(mockGameUI, displayGameName()).Times(1);
  EXPECT_CALL(mockGameUI, promptUserAction()).WillOnce(Return('s'));

  std::istringstream input(userInput);
  std::cin.rdbuf(input.rdbuf());

  game.start();
}

TEST(TestGame, TestPlayerTurn) {
  MockCardUI mockCardUI;
  MockPlayerView mockPlayerView(&mockCardUI);
  MockGameUI mockGameUI(&mockPlayerView);

  Game game(&mockGameUI);

  Player* player = new Player("Player 1");
  game.addPlayer(player);

  EXPECT_CALL(mockGameUI, displayHandStatus(_, _, player)).Times(1);
  EXPECT_CALL(mockGameUI, promptUserAction())
      .WillOnce(Return('h'))
      .WillOnce(Return('s'));
  EXPECT_CALL(mockGameUI, newCard()).Times(1);
  EXPECT_CALL(mockGameUI, displayHandStatus(_, _, player)).Times(1);
  EXPECT_CALL(mockGameUI, bustMessage()).Times(1);
  EXPECT_CALL(mockGameUI, invalidInput())
      .Times(0);  // Ensure invalidInput is not called

  game.playerTurn();
  delete player;
}

TEST(TestGame, TestDealerTurn) {
  MockCardUI mockCardUI;
  MockPlayerView mockPlayerView(&mockCardUI);
  MockGameUI mockGameUI(&mockPlayerView);

  Game game(&mockGameUI);

  EXPECT_CALL(mockGameUI, dealerValue(_)).Times(1);

  game.dealerTurn();
}

TEST(TestGame, TestCheckWinner) {
  MockCardUI mockCardUI;
  MockPlayerView mockPlayerView(&mockCardUI);
  MockGameUI mockGameUI(&mockPlayerView);

  Game game(&mockGameUI);

  Player* player = new Player("Player 1");
  game.addPlayer(player);

  EXPECT_CALL(mockGameUI, dealerValue(_)).Times(1);
  EXPECT_CALL(mockGameUI, win(player)).Times(1);

  game.checkWinner();
  delete player;
}

TEST(TestGame, TestIsGameOver) {
  MockCardUI mockCardUI;
  MockPlayerView mockPlayerView(&mockCardUI);
  MockGameUI mockGameUI(&mockPlayerView);

  Game game(&mockGameUI);

  EXPECT_CALL(mockGameUI, playAgain()).WillOnce(Return('n'));

  EXPECT_TRUE(game.isGameOver());
}
*/
