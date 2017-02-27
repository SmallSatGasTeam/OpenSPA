#ifndef COMPONENT_TEST_HPP
#define COMPONENT_TEST_HPP

#include "mocks/spa_communicator.hpp"
#include <component.hpp>
#include <messages/spa_subscription_reply.hpp>
#include <messages/spa_subscription_request.hpp>

class ExampleComponent : public Component
{
public:
  ExampleComponent(Component::Com com = nullptr, LogicalAddress address = LogicalAddress(0, 0)) : Component(com, address) {}

  virtual void appInit()
  {
    return;
  }
  
  virtual void sendSpaData(LogicalAddress la)
  {
    return;
  }

  virtual void handleSpaData(std::shared_ptr<SpaMessage> msg)
  {
    return;
  }
};

class ComponentTest : public ::testing::Test
{
public:
  virtual void SetUp()
  {
    spaCom = std::make_shared<MockSpaCommunicator>();
    subscriptionReply = std::make_shared<SpaSubscriptionReply>(

      0,                    // Version
      0,                    // Message priority
      LogicalAddress(0, 1), // Address of the producer component
      LogicalAddress(1, 0), // Address of the producer component
      0,                    // Dialog identifer sent by requester
      0                     // 0 = accepted
      );

    subscriptionRequest = std::make_shared<SpaSubscriptionRequest>(

      0,                    // Version
      0,                    // Message priority
      LogicalAddress(1, 0), // Address of the producer component
      LogicalAddress(0, 1), // Address of the consumer component
      LogicalAddress(0, 0), // Address of the subscriptions manager component
      0,                    // Duration of the subscription
      0,                    // Dialog identifier sent by requester
      1,                    // Subscribe to every nth message
      0,                    // xTEDS interface ID
      0,                    // xTEDS message Id
      0,                    // Subscription priority
      0                     // Message type (0 = subscription, 1 = unsubscribtion)
      );
  }

  std::shared_ptr<MockSpaCommunicator> spaCom;
  std::shared_ptr<SpaSubscriptionReply> subscriptionReply;
  std::shared_ptr<SpaSubscriptionRequest> subscriptionRequest;

};

TEST_F(ComponentTest, basic_tests)
{
  ExampleComponent component(spaCom, LogicalAddress(0, 0));
  EXPECT_NO_FATAL_FAILURE(component.subscribe(LogicalAddress(1, 1), 0, 0, 1));
  EXPECT_NO_FATAL_FAILURE(component.handleSubscriptionReply(subscriptionReply));
  EXPECT_NO_FATAL_FAILURE(component.registerSubscriptionRequest(subscriptionRequest));
  EXPECT_NO_FATAL_FAILURE(component.receiveMessage(subscriptionReply));
}

#endif
