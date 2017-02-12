#ifndef SPA_SUBSCRIPTION_REQUEST_HPP
#define SPA_SUBSCRIPTION_REQUEST_HPP
#include <cstdint>

#include <spa_message.hpp>

struct SpaSubscriptionRequest : public SpaMessage
{
  SpaSubscriptionRequest(
      uint8_t version,
      uint8_t priority,
      LogicalAddress producerAddress, // Address of the producer component
      LogicalAddress consumerAddress, // Address of the consumer component
      LogicalAddress managerAddress,  // Address of the subscriptions manager component
      uint32_t leasePeriod,           // Duration of the subscription, 0 = unlimited
      uint16_t dialogId,              // Dialog identier sent by requester
      uint16_t deliveryRateDivisor,   // Subscribe to every nth message
      uint8_t interfaceId,            // xTEDS interface Id
      uint8_t messageId,              // xTEDS message Id
      uint8_t subscriptionPriority,   // Subscription priority, 0 = highest, 255 = lowest
      uint8_t type                    // Message type, 0 = subscription, 1 = unsubscription
      ) : SpaMessage(version, priority, 96, producerAddress, consumerAddress, 0, 0x46),
          producerAddress(producerAddress),
          consumerAddress(consumerAddress),
          managerAddress(managerAddress),
          leasePeriod(leasePeriod),
          dialogId(dialogId),
          deliveryRateDivisor(deliveryRateDivisor),
          interfaceId(interfaceId),
          messageId(messageId),
          subscriptionPriority(subscriptionPriority),
          type(type)
  {
  }

  virtual ~SpaSubscriptionRequest() {}

  LogicalAddress producerAddress, consumerAddress, managerAddress;
  uint32_t leasePeriod;
  uint16_t dialogId;
  uint16_t deliveryRateDivisor;
  uint8_t interfaceId;
  uint8_t messageId;
  uint8_t subscriptionPriority;
  uint8_t type;
};
#endif
