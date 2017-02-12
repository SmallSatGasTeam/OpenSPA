#include <cstring>
#include <iostream>

#include <messages/local/local_ack.hpp>
#include <messages/local/local_hello.hpp>
#include <spa_message.hpp>

/*! Turns the object into a byte array for network transmission */
uint32_t SpaMessage::marshal(uint8_t *&target)
{
  uint32_t length = sizeof(*this);
  target = new uint8_t[length];
  memcpy(target, reinterpret_cast<uint8_t *>(this), length);
  return length;
}

/*! Takes a byte array and populates the object's data members */
std::shared_ptr<SpaMessage> SpaMessage::unmarshal(uint8_t *serialized, uint32_t size)
{
  auto msg = reinterpret_cast<SpaMessage *>(serialized);
  switch (msg->spaHeader.opcode)
  {
  case 0x20:
    return std::shared_ptr<LocalHello>(
        reinterpret_cast<LocalHello *>(serialized));
    break;
  case 0x21:
    return std::shared_ptr<LocalAck>(
        reinterpret_cast<LocalAck *>(serialized));
    break;
  }
  return nullptr;
}
