/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/model/BotPlayer.hpp"

BotPlayer::BotPlayer() : Player("Bot") {}

int BotPlayer::checkStatus() {
  int total = 0;
  int aceCount = 0;

  for (int i = 0; i < hand.size(); i++) {
    Card* c = hand[i];
    if (c->getRank() == Card::Rank::ACE) {
      aceCount++;
      total += 11;
    } else {
      total += c->getRankValue(c->getRank());
    }
  }

  // Adjust total if it exceeds 21 and there are Aces counted as 11
  while (total > 21 && aceCount > 0) {
    total -= 10;
    aceCount--;
  }

  return total;
}

void BotPlayer::hit(Deck* deck) {
  Card* newCard = deck->drawCard();
  addCard(newCard);
}
