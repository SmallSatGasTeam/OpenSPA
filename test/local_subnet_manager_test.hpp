#include <local_subnet_manager.hpp>
#include <component.hpp>
#include <logical_address.hpp>
#include <local_communicator.hpp>
#include "mocks/spa_communicator.hpp"

class LocalSubnetManagerTest : public ::testing::Test
{
public:
  virtual void SetUp()
  {
    opcode = 0x20;
    spaCom = std::make_shared<MockSpaCommunicator>();
  }
  uint8_t opcode;
  std::shared_ptr<MockSpaCommunicator> spaCom;
};

TEST_F(LocalSubnetManagerTest, add_component)
{
  LogicalAddress source(1, 1);
  LogicalAddress dest(1,0);

  SpaMessage msg(0,0,0,dest,source,0,opcode);
  LocalSubnetManager lsm(spaCom);
  
  lsm.receiveMessage(msg);
  EXPECT_TRUE(lsm.components.getAddress(0) == source);
}
