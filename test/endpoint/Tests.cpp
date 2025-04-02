/**
 * 
 */
#include <iostream>

#include "GameEndpointTest.hpp"

void runTests() {
  OATPP_RUN_TEST(GameStartTest);
  OATPP_RUN_TEST(AddPlayerTest);
  OATPP_RUN_TEST(StopGameTest);
  OATPP_RUN_TEST(DealTest);
  OATPP_RUN_TEST(DealerTurnTest);
  OATPP_RUN_TEST(GameStateTest);
  OATPP_RUN_TEST(StandTest);
  OATPP_RUN_TEST(HitTest);
  OATPP_RUN_TEST(ResetGameTest);
}

int main() {
  oatpp::base::Environment::init();

  runTests();

  /* Print how much objects were created during app running, and what have
   * left-probably leaked */
  /* Disable object counting for release builds using '-D
   * OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount()
            << "\n";
  std::cout << "objectsCreated = "
            << oatpp::base::Environment::getObjectsCreated() << "\n\n";

  OATPP_ASSERT(oatpp::base::Environment::getObjectsCount() == 0);

  oatpp::base::Environment::destroy();

  return 0;
}