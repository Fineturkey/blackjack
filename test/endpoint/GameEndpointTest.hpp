/**
 * @author Lance Tapang <lance.tapang@uleth.ca>
 * @author Sofiah Plarison <s.plarisan@uleth.ca>
 * @date Spring 2025
 */
#ifndef GameEndpointTest_hpp
#define GameEndpointTest_hpp

#include "oatpp-test/UnitTest.hpp"

class GameStartTest : public oatpp::test::UnitTest {
 public:
  GameStartTest() : UnitTest("TEST[GameServer - Start]") {}
  void onRun() override;
};

class AddPlayerTest : public oatpp::test::UnitTest {
 public:
  AddPlayerTest() : UnitTest("TEST[GameServer - Add Player]") {}
  void onRun() override;
};

class StopGameTest : public oatpp::test::UnitTest {
 public:
  StopGameTest() : UnitTest("TEST[GameServer - Stop Game]") {}
  void onRun() override;
};

class DealTest : public oatpp::test::UnitTest {
 public:
  DealTest() : UnitTest("TEST[GameServer - Deal]") {}
  void onRun() override;
};

class DealerTurnTest : public oatpp::test::UnitTest {
 public:
  DealerTurnTest() : UnitTest("TEST[GameServer - Dealer Turn]") {}
  void onRun() override;
};

class GameStateTest : public oatpp::test::UnitTest {
 public:
  GameStateTest() : UnitTest("TEST[GameServer - Game State]") {}
  void onRun() override;
};

class HitTest : public oatpp::test::UnitTest {
 public:
  HitTest() : UnitTest("TEST[GameServer - Hit]") {}
  void onRun() override;
};

class StandTest : public oatpp::test::UnitTest {
 public:
  StandTest() : UnitTest("TEST[GameServer - Stand]") {}
  void onRun() override;
};

class ResetGameTest : public oatpp::test::UnitTest {
 public:
  ResetGameTest() : UnitTest("TEST[GameServer - Reset Game]") {}
  void onRun() override;
};

#endif  // GameEndpointTest_hpp
