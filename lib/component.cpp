#include <iostream>
#include <memory>
#include "component.hpp"
#include "logical_address.hpp"

template <typename M>
void Component::sendMsg(M message)
{
  if (message == nullptr || communicator == nullptr)
  {
    return;
  }
  communicator->send(message);
}

template <typename M>
void Component::registerSubscriptionRequest(M message)
{
  auto reply = std::make_shared<SpaSubscriptionReply>(
    0, // Version
    0, // Message priority
    address, // Address of the producer component
    message->consumerAddress, // Address of the producer component
    message->dialogId, // Dialog identifer sent by requester
    0 // 0 = accepted
    );

  sendMsg(reply);
}

template <typename M>
void Component::handleSubscriptionReply(M message)
{
  if (message->replyType != 0) 
  {
    std::cout << "Subscription failed." << std::endl;
  }
  else
  {
    std::cout << "Subscription succeeded." << std::endl; 
  }
}

template <typename M>
void Component::receiveMessage(M message)
{
  if (message == nullptr) return;

  else if (message->opcode == 0x46) // Subscription request
  {
    registerSubscriptionRequest(message); 
  }
  else if (message->opcode == 0x47) // Subscription reply
  {
    handleSubscriptionReply(message);
  }
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
   dialogId, // Dialog identifier sent by requester
   deliveryRateDivisor, // Subscribe to every nth message
   0, // xTEDS interface ID
   0, // xTEDS message Id
   priority, // Subscription priority
   0 // Message type (0 = subscription, 1 = unsubscribtion)
   );

  sendMsg(request);
  ++dialogId;
}
