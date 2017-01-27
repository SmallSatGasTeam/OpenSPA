#ifndef LOCAL_ACK_HPP
#define LOCAL_ACK_HPP

#include <cstdint>
#include <messages/local/local_spa_message.hpp>

struct LocalAck : public LocalSpaMessage
{
  LocalAck(
    uint8_t version,
    uint8_t priority,
    LogcialAddress destination,
    LogicalAddress source,
    uint16_t flags,
    uint16_t sourcePort,
    uint8_t status; 
  ):LocalSpaMessage(
    version,
    priority,
    72,
    destination,
    source,
    flags,
    0x21,
    sourcePort
  ), status(status) {}

  uint8_t status; // The status of the acknowledgement
};
#endif
