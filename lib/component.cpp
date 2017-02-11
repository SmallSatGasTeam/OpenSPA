#include "component.hpp"
#include "logical_address.hpp"

template <typename T>
void Component::sendMsg(T message)
{
  if (message == nullptr || communicator == nullptr)
  {
    return;
  }
  communicator->send(message);
}

void Component::subscribe(
  LogicalAddress producer,
  uint8_t priority,
  uint32_t leasePeriod,
  uint16_t deliveryRateDivisor)
{
  auto request = std::make_shared<SpaSubscriptionRequest>(
   0, // Version
   0, // Message priority
   producer, // Address of the producer component
   address, // Address of the consumer component
   LogicalAddress(0,0), // Address of the subscriptions manager component
   leasePeriod, // Duration of the subscription
   dialodId, // Dialog identifier sent by requester
   deliveryRateDivisor, // Subscribe to every nth message
   0, // xTEDS interface ID
   0, // xTEDS message Id
   priority, // Subscription priority
   0 // Message type (0 = subscription, 1 = unsubscribtion)
   );

  sendMsg(request);
}
