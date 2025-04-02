/**
 * @author Sofiah Plarisan <s.plarisan@uleth.ca>
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/model/Player.hpp"

#include <iostream>

Player::Player(std::string name) : name(name) {}

Player::~Player() {
  for (Card* c : hand) {
    delete c;
  }
}

std::string Player::getName() const { return name; }

bool Player::isBusted() const { return getHandValue() > BUSTLIMIT; }

void Player::addCard(Card* card) { hand.push_back(card); }

void Player::clearHand() {
  for (Card* c : hand) {
    delete c;
  }
  hand.clear();
}

std::vector<Card*> Player::getHand() { return hand; }

int Player::getHandSize() { return hand.size(); }

int Player::getHandValue() const {
  int value = 0;
  int aceCount = 0;

  for (Card* card : hand) {
    value += card->getRankValue(card->getRank());

    if (card->getRank() == Card::Rank::ACE) {
      aceCount++;
    }
  }

  for (int i = 0; i < aceCount; ++i) {
    if (value + 10 <= BUSTLIMIT) {
      value += 10;
    }
  }

  return value;
}

void Player::stand() {}

void Player::hit(Deck* deck) {
  if (isBusted()) {
    return;
  }
  Card* newCard = deck->drawCard();
  addCard(newCard);
}
