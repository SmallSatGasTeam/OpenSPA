#include "component.hpp"
#include "logical_address.hpp"
#include "messages/spa_subscription_reply.hpp"
#include "messages/spa_subscription_request.hpp"
#include "messages/op_codes.hpp"
#include <iostream>
#include <memory>

void Component::registerSubscriptionRequest(std::shared_ptr<SpaMessage> message)
{
  if (message == nullptr)
    return;

  auto castMessage = std::dynamic_pointer_cast<SpaSubscriptionRequest>(message);

  auto reply = std::make_shared<SpaSubscriptionReply>(
      0,                            // Version
      0,                            // Message priority
      address,                      // Address of the producer component
      castMessage->consumerAddress, // Address of the producer component
      castMessage->dialogId,        // Dialog identifer sent by requester
      0                             // 0 = accepted
      );

  sendMsg(reply);
}

void Component::handleSubscriptionReply(std::shared_ptr<SpaMessage> message)
{
  if (message == nullptr)
    return;
  auto castMessage = std::dynamic_pointer_cast<SpaSubscriptionReply>(message);

  // TODO actually implement subscription handling
  if (castMessage->replyType != 0)
  {
    std::cout << "Subscription failed." << std::endl;
  }
  else
  {
    std::cout << "Subscription succeeded." << std::endl;
  }
}
void Component::subscribe(
    LogicalAddress producer,
    uint8_t priority,
    uint32_t leasePeriod,
    uint16_t deliveryRateDivisor)
{
  auto request = std::make_shared<SpaSubscriptionRequest>(
      0,                    // Version
      0,                    // Message priority
      producer,             // Address of the producer component
      address,              // Address of the consumer component
      LogicalAddress(0, 0), // Address of the subscriptions manager component
      leasePeriod,          // Duration of the subscription
      dialogId,             // Dialog identifier sent by requester
      deliveryRateDivisor,  // Subscribe to every nth message
      0,                    // xTEDS interface ID
      0,                    // xTEDS message Id
      priority,             // Subscription priority
      0                     // Message type (0 = subscription, 1 = unsubscribtion)
      );

  sendMsg(request);
  ++dialogId;
}

void Component::receiveMessage(std::shared_ptr<SpaMessage> message)
{
  if (message == nullptr)
  {
    return;
  }
  else if (message->spaHeader.opcode == op_SPA_SUBSCRIPTION_REQUEST)
  {
    registerSubscriptionRequest(message);
  }
  else if (message->spaHeader.opcode == op_SPA_SUBSCRIPTION_REPLY)
  {
    handleSubscriptionReply(message);
  }
  else
  {
    std::cout << "Unrecognized message" << std::endl;
  }
}
