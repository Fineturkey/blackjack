/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/model/Dealer.hpp"

#include "../../include/model/Card.hpp"
#include "../../include/model/Deck.hpp"
#include "../../include/model/Player.hpp"

Dealer::~Dealer() {
  delete deck;
  clearDealerHand();
}

void Dealer::addCard(Card* c) { hand.push_back(c); }

void Dealer::deal(std::vector<Player*> players) {
  deck->shuffle();
  for (auto p : players) {
    p->addCard(deck->drawCard());
  }
  addCard(deck->drawCard());
  for (auto p : players) {
    p->addCard(deck->drawCard());
  }
}

Card* Dealer::dealSingleCard() { return deck->drawCard(); }

int Dealer::checkStatus() {
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

int Dealer::getHandSize() { return hand.size(); }

void Dealer::clearDealerHand() {
  for (Card* c : hand) {
    delete c;
  }
  hand.clear();
}

std::vector<Card*> Dealer::getHand() { return hand; }

int Dealer::getCardValue(Card* c) { return c->getRankValue(c->getRank()); }
