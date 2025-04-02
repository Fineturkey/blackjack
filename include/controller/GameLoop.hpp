/**
 * @author Eugene Gu <e.gu@uleth.ca>
 * @date Spring 2025
 * @brief Defines the GameLoop class, which manages the main game loop.
 */

#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP

#include <iostream>
#include "../../include/controller/Game.hpp"

/**
  * @class GameLoop
  * @brief Handles the execution of the game loop.
  */
class GameLoop {
 public:
   /**
    * @brief Runs the game loop until the game is over.
    */
  void run();
};
#endif  // GAME_LOOP_HPP
