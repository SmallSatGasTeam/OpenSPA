#include <cstdint>
#include <string>
#include <memory>
#include <vector>


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "spa_communicator_test.hpp"
#include "routing_table_test.hpp"
// #include "network_communicator_test.hpp"
#include "local_communicator_test.hpp"
#include "subnet_manager_test.hpp"
#include "spa_message_test.hpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
