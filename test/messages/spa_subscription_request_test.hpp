#include <messages/spa_subscription_request.hpp>

TEST(SpaSubscriptionRequest, constructor)
{
  SpaSubscriptionRequest message(
      0,                    // uint8_t version,
      0,                    // uint8_t priority,
      LogicalAddress(1, 1), // LogicalAddress producerAddress,
      LogicalAddress(1, 2), // LogicalAddress consumerAddress,
      LogicalAddress(),     // LogicalAddress managerAddress,
      9000000,              // uint32_t leasePeriod,
      0,                    // uint16_t dialogId,
      5,                    // uint16_t deliveryRateDivisor,
      0,                    // uint8_t interfaceId,
      0,                    // uint8_t messageId,
      125,                  // uint8_t subscriptionPriority,
      1                     // uint8_t type
      );

  EXPECT_EQ(message.type, 1);
}
