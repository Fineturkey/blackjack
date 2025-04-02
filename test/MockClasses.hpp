#ifndef MOCKCLASSES_HPP
#define MOCKCLASSES_HPP

#include <vector>

#include "CardUI.hpp"
#include "GameUI.hpp"
#include "PlayerView.hpp"
#include "gmock/gmock.h"

class MockCardUI : public CardUI {
 public:
  MOCK_METHOD(void, displaySuit, (Card::Suit s));
  MOCK_METHOD(void, displayRank, (Card::Rank r));
};

class MockPlayerView : public PlayerView {
 public:
  MockPlayerView(CardUI* cardUI) : PlayerView(cardUI) {}
  MOCK_METHOD(void, displayHand,
              (const std::vector<Card*>& hand, int handValue,
               const Player* player));
};

class MockGameUI : public GameUI {
 public:
  MockGameUI(PlayerView* playerView) : GameUI(playerView) {}
  MOCK_METHOD(void, displayGameName, ());
  MOCK_METHOD(void, displayHandStatus,
              (const std::vector<Card*>& hand, int handValue,
               const Player* player));
  MOCK_METHOD(char, promptUserAction, ());
  MOCK_METHOD(void, bustMessage, ());
  MOCK_METHOD(void, invalidInput, ());
  MOCK_METHOD(void, dealerValue, (int value));
  MOCK_METHOD(void, bust, (const Player* player));
  MOCK_METHOD(void, win, (const Player* player));
  MOCK_METHOD(void, loses, (const Player* player));
  MOCK_METHOD(void, push, (const Player* player));
  MOCK_METHOD(char, playAgain, ());
  MOCK_METHOD(void, newCard, ());
};

#endif  // MOCKCLASSES_HPP
