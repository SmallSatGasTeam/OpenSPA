#ifndef COMPONENT_TEST_HPP
#define COMPONENT_TEST_HPP

#include <component.hpp>
#include <messages/spa_subscription_reply.hpp>
#include "mocks/spa_communicator.hpp"

class ExampleComponent : public Component
{
public:
  ExampleComponent(Component::Com com = nullptr, LogicalAddress address = LogicalAddress(0,0)) : Component(com, address) {}

  virtual void appInit()
  {
    return;
  }
};

class ComponentTest : public ::testing::Test
{
public:
  virtual void SetUp()
  {
    /*
    uint16_t port = 8888;
    std::shared_ptr<ServerSocket> sock = std::make_shared<ServerSocket>();
    std::shared_ptr<RoutingTable> routingTable = std::make_shared<RoutingTable>();
    routingTable->insert(LogicalAddress(1, 3), 8888);

    LogicalAddress localAddress(1, 0);
    std::vector<SpaCommunicator::Com> comms = {
    std::make_shared<LocalCommunicator>(sock, routingTable, localAddress)};
    std::shared_ptr<SpaCommunicator> spaCom = std::make_shared<SpaCommunicator>(localAddress, comms);

    component = ExampleComponent(spaCom, LogicalAddress(0,0));
    */
  } 

  std::shared_ptr<MockSpaCommunicator> spaCom = std::make_shared<MockSpaCommunicator>();
  std::shared_ptr<SpaSubscriptionReply> subscriptionReply = std::make_shared<SpaSubscriptionReply>(
    0, // Version
    0, // Message priority
    LogicalAddress(0,1), // Address of the producer component
    LogicalAddress(1,0), // Address of the producer component
    0, // Dialog identifer sent by requester
    0 // 0 = accepted
    );

  std::shared_ptr<SpaSubscriptionRequest> subscriptionRequest = std::make_shared<SpaSubscriptionRequest>(
   0, // Version
   0, // Message priority
   LogicalAddress(1,0), // Address of the producer component
   LogicalAddress(0,1), // Address of the consumer component
   LogicalAddress(0,0), // Address of the subscriptions manager component
   0, // Duration of the subscription
   0, // Dialog identifier sent by requester
   1, // Subscribe to every nth message
   0, // xTEDS interface ID
   0, // xTEDS message Id
   0, // Subscription priority
   0 // Message type (0 = subscription, 1 = unsubscribtion)
   );



};

TEST_F(ComponentTest, basic_tests)
{
  ExampleComponent component(spaCom, LogicalAddress(0,0));


  EXPECT_NO_FATAL_FAILURE(component.subscribe(LogicalAddress(1,1),0,0,1)); 
  EXPECT_NO_FATAL_FAILURE(component.handleSubscriptionReply(subscriptionReply));
  EXPECT_NO_FATAL_FAILURE(component.registerSubscriptionRequest(subscriptionRequest));
  EXPECT_NO_FATAL_FAILURE(component.receiveMessage(subscriptionReply));
} 


#endif
