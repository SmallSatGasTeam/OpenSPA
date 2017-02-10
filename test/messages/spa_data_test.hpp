#include <messages/spa_data.hpp>

TEST(SpaData, constructor)
{
  SpaData<uint32_t> message(
  0,  // uint8_t version,
  0,  // uint8_t priority,
  LogicalAddress(1,1),  // LogicalAddress producerAddress,
  LogicalAddress(1,2),  // LogicalAddress consumerAddress,
  0,  // uint16_t dialogId,
  0,  // uint16_t sequenceIndex,
  0,  // uint16_t sequenceCount,
  0,  // uint8_t interfaceId,
  0,  // uint8_t messageId,
  44  // T payload
  );
 
  EXPECT_EQ(message.payload, 44);
}
