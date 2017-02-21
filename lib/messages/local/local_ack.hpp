#ifndef LOCAL_ACK_HPP
#define LOCAL_ACK_HPP

#include <cstdint>
#include <messages/local/local_spa_message.hpp>
#include <messages/op_codes.hpp

struct LocalAck : public LocalSpaMessage
{
  LocalAck(
      uint8_t version,
      uint8_t priority,
      LogicalAddress destination,
      LogicalAddress source,
      uint16_t flags,
      uint16_t sourcePort,
      uint8_t status) : LocalSpaMessage(version,
                                        priority,
                                        72,
                                        destination,
                                        source,
                                        flags,
                                        op_LOCAL_ACK,
                                        sourcePort),
                        status(status) {}

  uint8_t status; // The status of the acknowledgement
};
#endif
