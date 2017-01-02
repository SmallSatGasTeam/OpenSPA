#include <spa_message.hpp>

class SpaMessageTest : public ::testing::Test {
public:
  virtual void SetUp(){
    opcode = 9;
  }

  uint8_t opcode;
};

TEST_F(SpaMessageTest, marshal){
  LogicalAddress la(1,1);
  SpaMessage original(la, opcode);
  uint8_t buff[512];
  uint32_t length = original.marshal(buff);

  SpaMessage* clone = reinterpret_cast<SpaMessage*>(buff);

  EXPECT_TRUE(clone != nullptr);
  EXPECT_EQ(original.opcode, clone->opcode);
  EXPECT_EQ(original.logicalAddress.subnetId, clone->logicalAddress.subnetId);
  EXPECT_EQ(original.logicalAddress.componentId, clone->logicalAddress.componentId);
  EXPECT_EQ(length, sizeof(SpaMessage));
}
