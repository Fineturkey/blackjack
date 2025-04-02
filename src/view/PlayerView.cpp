/**
 * @author Sofiah Plarisan <s.plarisan@uleth.ca>
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/view/PlayerView.hpp"

#include <iostream>

#include "../../include/model/Player.hpp"
#include "../../include/view/CardUI.hpp"

PlayerView::~PlayerView() { delete cardUI; }

void PlayerView::displayHand(std::vector<Card*> hand, int handValue,
                             const Player* p) {
  std::cout << p->getName() << ", your hand is: ";
  for (Card* card : hand) {
    std::cout << "[";
    std::cout << cardUI->displayRank(card->getRank());
    std::cout << " of ";
    std::cout << cardUI->displaySuit(card->getSuit());
    std::cout << "], ";
  }
  std::cout << "Value: " << handValue << std::endl;
}

void PlayerView::displayDealersFirstCard(Dealer* dealer,
                                         std::vector<Card*> hand) {
  std::cout << "Dealer's first card: ";
  std::cout << "[";
  std::cout << cardUI->displayRank(hand[0]->getRank());
  std::cout << " of ";
  std::cout << cardUI->displaySuit(hand[0]->getSuit());
  std::cout << "], ";
  std::cout << "Value: " << dealer->getCardValue(hand[0]) << std::endl;
}

void PlayerView::displayDealersHand(Dealer* dealer, std::vector<Card*> hand) {
  std::cout << "Dealer's hand is: ";
  for (Card* card : hand) {
    std::cout << "[";
    std::cout << cardUI->displayRank(card->getRank());
    std::cout << " of ";
    std::cout << cardUI->displaySuit(card->getSuit());
    std::cout << "], ";
  }
  std::cout << "Value: " << dealer->checkStatus() << std::endl;
}

char PlayerView::promptUserAction() {
  char choice;
  std::cout << "Do you want to hit (h) or stand (s)? ";
  std::cin >> choice;
  return choice;
}

void PlayerView::displayBustMessage() {
  std::cout << "You busted!" << std::endl;
}

void PlayerView::displayInvalidInput() {
  std::cout << "Invalid input. "
            << "Please enter the correct input." << std::endl;
}
