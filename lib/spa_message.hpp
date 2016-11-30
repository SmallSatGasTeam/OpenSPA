#ifndef SPA_MESSAGE_HPP
#define SPA_MESSAGE_HPP
#include <cstdint>
#include "logical_address.hpp"


//! Class to represent generic spa message. Should be extended by other Spa Message
//! types
struct SpaMessage{

  //! Generate a message from a logical address and an opcode

  //! \param la - locial address of message
  //! \param opc - message opcode
  SpaMessage(LogicalAddress la, uint8_t opc):logicalAddress(la), opcode(opc){}

  //! Generate a message from a byte array

  //! \param serialized - array containing serialized message
  //! \param size - length of serialized array
  SpaMessage(uint8_t* serialized, uint32_t size);

  //! Serializes a message to a byte array

  //! \param target - pointer where seialized message array will be stored
  //! \return - size of serialized array
  uint32_t marshal(uint8_t* target);

  //! Logical address of component on spa network
  LogicalAddress logicalAddress;

  //! Operation code of spa message. These are specified in the Spa Specification
  uint8_t opcode;
};
#endif
