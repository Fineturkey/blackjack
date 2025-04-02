# Template for CPSC2720 Minor Project creating a card game

Last Updated: 2023-12-15 by Nicole Wilson &lt;n.wilson@uleth.ca&gt;

Notes:

* The Makefile and .gitlab-ci.yml files are set up to run on Ubuntu.
* The .gitlab-ci.yml file uses the targets in the Makefile.
* These are the tools/commands/apps used:
  * Compiler: g++
  * Version: c++14
  * Style Check: cpplint 1.6.1
  * Static Check: cppcheck 1.90

Certain assumptions have been made:
* One repo contains the files for one project.
* All header files for the project are found in <code>include/</code> and named <code>*.h</code>, every class must have a header file and the name of the file starts with a capital letter.
* All project source files for the project are named <code>*.cpp</code>.
  * Any needed source files that correspond to header files are found in <code>src/</code>.
  * There is a <code>main.cpp</code> found in <code>src/project/</code>.


# ENDPOINTS:
* "http://localhost:8200/game/start" Starts the Game
* "http://localhost:8200/game/addPlayer/Player1" Adds a player
* "http://localhost:8200/game/addPlayer/Player2" Adds a player
* "http://localhost:8200/game/deal" Deals cards to players
* "http://localhost:8200/game/playerState" Checks players hands
* "http://localhost:8200/game/dealerState Checks dealer hand
* "http://localhost:8200/game/hit/Player1" Makes Player1 hit
* "http://localhost:8200/game/playerState" Checks players hands

* If Player1 is bust continue to player2 stand, if not:

* "http://localhost:8200/game/stand/Player1" Makes Player2 Stand
* "http://localhost:8200/game/stand/Player2" Makes Player2 stand
* "http://localhost:8200/game/playerState" Checks players hands
* "http://localhost:8200/game/dealerTurn" Dealer plays

* "http://localhost:8200/game/isOver" Checks if game is over
