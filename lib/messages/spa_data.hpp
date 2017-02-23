#ifndef SPA_DATA_HPP
#define SPA_DATA_HPP

#include <cstdint>
#include <climits>
#include "op_codes.hpp"


template <typename T>
struct SpaData : public SpaMessage
{
  SpaData(
      uint8_t version,
      uint8_t priority,
      LogicalAddress producerAddress,
      LogicalAddress consumerAddress,
      uint16_t dialogId,
      uint16_t sequenceIndex,
      uint16_t sequenceCount,
      uint8_t interfaceId,
      uint8_t messageId,
      T payload) : SpaMessage(version, priority, 100 + payloadLength, producerAddress, consumerAddress, 0, op_SPA_DATA),
                   dialogId(dialogId),
                   sequenceIndex(sequenceIndex),
                   sequenceCount(sequenceCount),
                   interfaceId(interfaceId),
                   messageId(messageId),
                   payload(payload) {}

  uint16_t payloadLength = sizeof(payload) * CHAR_BIT;
  uint16_t dialogId;
  uint16_t sequenceIndex;
  uint16_t sequenceCount;
  uint8_t interfaceId;
  uint8_t messageId;
  T payload;
};
#endif
