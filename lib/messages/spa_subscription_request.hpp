#ifndef SPA_SUBSCRIPTION_REQUEST_HPP
#define SPA_SUBSCRIPTION_REQUEST_HPP
#include <cstdint>

#include <spa_message.hpp>

struct SpaSubscriptionRequest:public SpaMessage{
  SpaSubscriptionRequest(
    uint8_t version,
    uint8_t priority,
    LogicalAddress producerAddress,
    LogicalAddress consumerAddress,
    LogicalAddress managerAddress,
    uint32_t leasePeriod,
    uint16_t dialogId,
    uint16_t deliveryRateDivisor,
    uint8_t interfaceId,
    uint8_t messageId,
    uint8_t subscriptionPriority,
    uint8_t type
  ):
  SpaMessage(version, priority, 96, producerAddress, consumerAddress, 0, 0x46),
  producerAddress(producerAddress),
  consumerAddress(consumerAddress),
  managerAddress(managerAddress),
  leasePeriod(leasePeriod),
  dialogId(dialogId),
  deliveryRateDivisor(deliveryRateDivisor),
  interfaceId(interfaceId),
  messageId(messageId),
  subscriptionPriority(subscriptionPriority),
  type(type){}

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
