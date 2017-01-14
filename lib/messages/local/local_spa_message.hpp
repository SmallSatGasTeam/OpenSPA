#ifndef LOCAL_SPA_MESSAGE
#define LOCAL_SPA_MESSAGE
#include <cstdint>

#include <spa_message.hpp>
#include <messages/spa_local_header.hpp>

struct LocalSpaMessage:public SpaMessage{
  LocalSpaMessage(
    uint8_t version,
    uint8_t priority,
    uint16_t length,
    LogicalAddress destination,
    LogicalAddress source,
    uint16_t flags,
    uint8_t opcode,
    uint16_t sourcePort
  ):
    SpaMessage(version, priority, length, destination, source, flags, opcode),
    spaLocalHeader(sourcePort, length, opcode){}

  SpaLocalHeader spaLocalHeader;
};
#endif
