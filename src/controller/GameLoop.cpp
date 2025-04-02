/**
 * @authors Eugene Gu <e.gu@uleth.ca>, Austin Savoie <austin.savoie@uleth.ca>
 * @date Spring 2025
 */
#include "../../include/controller/GameLoop.hpp"

void GameLoop::run() {
  CardUI* cardUI = new CardUI();
  PlayerView* playerView = new PlayerView(cardUI);
  GameUI* gameUI = new GameUI(playerView);
  Deck* deck = new Deck();
  Dealer* dealer = new Dealer(deck);
  Game* game = new Game(gameUI, dealer);
  bool running = true;
  while (running) {
    game->start();
    running = !game->checkWinner();
  }
  std::cout << "Thanks for playing!\n";
  delete game;
}
