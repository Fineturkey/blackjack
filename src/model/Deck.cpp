/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/model/Deck.hpp"

#include <algorithm>
#include <random>
#include <vector>

Deck::Deck() {
  for (int s = 0; s <= 3; s++) {
    for (int r = 0; r <= 12; r++) {
      deck.push_back(
          new Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)));
    }
  }
}

Deck::~Deck() {
  for (auto c : deck) {
    delete c;
  }
}

void Deck::shuffle() {
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(deck.begin(), deck.end(), g);
}

void Deck::addCard(Card* c) { deck.push_back(c); }

void Deck::removeCard(Card* c) {
  deck.erase(std::remove(deck.begin(), deck.end(), c), deck.end());
}

Card* Deck::drawCard() {
  Card* c = deck.back();
  deck.pop_back();
  return c;
}

int Deck::getNumCards() { return deck.size(); }
