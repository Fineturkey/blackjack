/**
 * @author Eugene Gu <e.gu@uleth.ca>
 * @author Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/controller/Game.hpp"

#include <iostream>

Game::Game(GameUI* gameUI, Dealer* dealer) : gameUI(gameUI), dealer(dealer) {}

Game::~Game() {
  delete dealer;
  delete gameUI;
  for (auto p : players) {
    delete p;
  }
}

void Game::start() {
  gameUI->displayGameName();
  playerInit();
  dealer->deal(players);
  playerTurn();
  dealerTurn();
}

void Game::playerInit() {
  int numPlayers = gameUI->getNumPlayers();
  std::vector<std::string> names = gameUI->getPlayerNames(numPlayers);
  for (int i = 0; i < numPlayers; i++) {
    Player* p = new Player(names[i]);
    addPlayer(p);
  }
}

void Game::playerTurn() {
  gameUI->displayDealersCard(dealer->getHand(), dealer);
  for (auto p : players) {
    bool turnOver = false;
    while (!turnOver) {
      gameUI->displayHandStatus(p->getHand(), p->getHandValue(), p);
      char choice = gameUI->promptUserAction();

      if (choice == 'h' && !p->isBusted()) {
        p->addCard(dealer->dealSingleCard());
        gameUI->newCard();

        if (p->isBusted()) {
          gameUI->bustMessage();
          turnOver = true;
        }
      } else if (choice == 's') {
        turnOver = true;
      } else {
        gameUI->invalidInput();
      }
    }
  }
}

void Game::dealerTurn() {
  gameUI->displayDealerHand(dealer->getHand(), dealer);
  if (dealer->getHandSize() == 1) {
    dealer->addCard(dealer->dealSingleCard());
  }
  while (dealer->checkStatus() < 17) {
    dealer->addCard(dealer->dealSingleCard());
    gameUI->displayDealerHand(dealer->getHand(), dealer);
  }
}

bool Game::checkWinner() {
  int dealerValue = dealer->checkStatus();
  gameUI->dealerValue(dealerValue);

  for (auto p : players) {
    int playerValue = p->getHandValue();

    if (p->isBusted()) {
      gameUI->bust(p);
    } else if (dealerValue > 21 || playerValue > dealerValue) {
      gameUI->win(p);
    } else if (playerValue < dealerValue) {
      gameUI->loses(p);
    } else {
      gameUI->push(p);
    }
  }
  return true;
}

void Game::addPlayer(Player* p) { players.push_back(p); }

const std::vector<Player*>& Game::getPlayers() const { return players; }

Player* Game::getPlayerByName(const std::string& name) {
  for (auto p : players) {
    if (p->getName() == name) {
      return p;
    }
  }
  return nullptr;
}

void Game::deal() { dealer->deal(players); }
