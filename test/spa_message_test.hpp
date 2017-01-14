#include <messages/test_derived_message.hpp>
#include <spa_message.hpp>

class SpaMessageTest : public ::testing::Test
{
public:
  virtual void SetUp()
  {
    opcode = 9;
  }
  uint8_t opcode;
};

TEST_F(SpaMessageTest, marshal)
{
  LogicalAddress la(1, 1);
  SpaMessage original(la, opcode);
  uint8_t *buff = new uint8_t[512];
  uint32_t length = original.marshal(buff);

  SpaMessage *clone = reinterpret_cast<SpaMessage *>(buff);

  EXPECT_TRUE(clone != nullptr);
  EXPECT_EQ(original.spaHeader.opcode, clone->spaHeader.opcode);
  EXPECT_EQ(original.spaHeader.destination.subnetId, clone->spaHeader.destination.subnetId);
  EXPECT_EQ(original.spaHeader.destination.componentId, clone->spaHeader.destination.componentId);
  EXPECT_EQ(length, sizeof(SpaMessage));
}

TEST_F(SpaMessageTest, unmarshal)
{
  LogicalAddress la(1, 1);
  TestDerivedMessage original(la);
  uint8_t *buff = new uint8_t[512];
  uint32_t length = original.marshal(buff);

  std::shared_ptr<SpaMessage> clone = SpaMessage::unmarshal(buff, length);

  EXPECT_TRUE(clone != nullptr);
  EXPECT_EQ(original.spaHeader.opcode, clone->spaHeader.opcode);
  EXPECT_EQ(original.spaHeader.destination.subnetId, clone->spaHeader.destination.subnetId);
  EXPECT_EQ(original.spaHeader.destination.componentId, clone->spaHeader.destination.componentId);
  EXPECT_EQ(length, sizeof(SpaMessage));
}
