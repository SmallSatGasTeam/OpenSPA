#include <messages/spa_subscription_reply.hpp>

TEST(SpaSubscriptionReply, constructor)
{
  SpaSubscriptionReply message(
      0,
      0,
      LogicalAddress(1, 1),
      LogicalAddress(1, 2),
      0,
      0);

  EXPECT_EQ(message.dialogId, 0);
}
