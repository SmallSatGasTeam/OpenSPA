#ifndef LOCAL_HELLO_HPP
#define LOCAL_HELLO_HPP
#include <cstdint>

#include <messages/local/local_spa_message.hpp>
struct LocalHello : public LocalSpaMessage
{

  // CUUID UInt128 UUID Universally Unique Id of the SPA component
  // ComponentType UInt8 n/a The type of SPA component

  LocalHello(
      uint8_t version,
      uint8_t priority,
      LogicalAddress destination,
      LogicalAddress source,
      uint16_t flags,
      uint16_t sourcePort,
      uint64_t uuid,
      uint8_t componentType)
    : LocalSpaMessage(version,
                      priority,
                      72,
                      destination,
                      source,
                      flags,
                      0x20,
                      sourcePort),
      uuid(uuid),
      componentType(componentType) {}

  uint64_t uuid;
  // uint64_t uuidBack; // NOTE c++ standard does not have a 128 bit width integer
  uint8_t componentType;
};
#endif
