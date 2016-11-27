#include <gtest/gtest.h>

#include "spa_communicator.hpp"
#include "routing_table.hpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}