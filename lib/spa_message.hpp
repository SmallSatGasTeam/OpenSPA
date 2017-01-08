#ifndef SPA_MESSAGE_HPP
#define SPA_MESSAGE_HPP
#include <cstdint>
#include <memory>

#include "logical_address.hpp"

//! Class to represent generic spa message. Should be extended by other Spa Message
//! types
struct SpaMessage
{

  //! Generate a message from a logical address and an opcode

  //! \param la - locial address of message
  //! \param opc - message opcode
  SpaMessage(LogicalAddress la, uint8_t opc)
      : logicalAddress(la), opcode(opc){}
  SpaMessage() : opcode(0){}

  //! Generate a message from a byte array

  //! \param serialized - array containing serialized message
  //! \param size - length of serialized array
  SpaMessage(uint8_t *serialized, uint32_t size);

  //! Serializes a message to a byte array

  //! \param target - pointer where seialized message array will be stored
  //! \return - size of serialized array
  uint32_t marshal(uint8_t *&target);

  //TODO document
  static std::shared_ptr<SpaMessage> unmarshal(uint8_t *serialized, uint32_t size);

  //! Logical address of component on spa network
  LogicalAddress logicalAddress;

  uint8_t version;
  uint8_t priority;
  uint16_t length;
  LogicalAddress destination;
  LogicalAddress source;
  uint16_t flags;
  uint8_t opcode;

  static uint8_t const TEST_TYPE = 1;
};
#endif
