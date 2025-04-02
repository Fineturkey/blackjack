/**
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/view/GameUI.hpp"

#include <iostream>

#include "../../include/model/Player.hpp"
#include "../../include/view/PlayerView.hpp"

GameUI::GameUI(PlayerView* UI) : playerUI(UI) {}

GameUI::~GameUI() { delete playerUI; }

void GameUI::displayGameName() { std::cout << "Welcome to Blackjack!\n"; }

void GameUI::displayDealersCard(std::vector<Card*> hand, Dealer* dealer) {
  playerUI->displayDealersFirstCard(dealer, hand);
}

void GameUI::displayDealerHand(std::vector<Card*> hand, Dealer* dealer) {
  playerUI->displayDealersHand(dealer, hand);
}

void GameUI::displayHandStatus(const std::vector<Card*> hand, int handValue,
                               const Player* p) {
  playerUI->displayHand(hand, handValue, p);
}

char GameUI::promptUserAction() { return playerUI->promptUserAction(); }

void GameUI::bustMessage() { playerUI->displayBustMessage(); }

void GameUI::invalidInput() { playerUI->displayInvalidInput(); }

void GameUI::dealerValue(int dealerValue) {
  std::cout << "Dealer's hand value: " << dealerValue << "\n";
}

void GameUI::bust(Player* p) { std::cout << p->getName() << " busted!\n"; }

void GameUI::win(Player* p) { std::cout << p->getName() << " wins!\n"; }

void GameUI::loses(Player* p) { std::cout << p->getName() << " loses!\n"; }

void GameUI::push(Player* p) { std::cout << p->getName() << " pushes!\n"; }

char GameUI::playAgain() {
  std::cout << "Do you want to play again? (y/n): ";
  char choice;
  std::cin >> choice;
  return choice;
}

void GameUI::newCard() { std::cout << "You drew a card! "; }

int GameUI::getNumPlayers() {
  int numPlayers;
  std::cout << "Enter the number of players: ";
  std::cin >> numPlayers;
  return numPlayers;
}

std::vector<std::string> GameUI::getPlayerNames(int numPlayers) {
  std::string name;
  std::vector<std::string> names;
  std::cout << "Enter the name of each player: \n";
  for (int i = 0; i < numPlayers; i++) {
    std::cout << "Player " << i + 1 << ": ";
    std::cin >> name;
    names.push_back(name);
  }
  return names;
}
