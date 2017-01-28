#include <cstring>
#include <iostream>

#include <messages/local/local_hello.hpp>
#include <spa_message.hpp>

//TODO document
uint32_t SpaMessage::marshal(uint8_t *&target)
{
  uint32_t length = sizeof(*this);
  target = new uint8_t[length];
  memcpy(target, reinterpret_cast<uint8_t *>(this), length);
  return length;
}

std::shared_ptr<SpaMessage> SpaMessage::unmarshal(uint8_t *serialized, uint32_t size)
{
  auto msg = reinterpret_cast<SpaMessage *>(serialized);
  switch (msg->spaHeader.opcode)
  {
  case 0x20:
    return std::shared_ptr<LocalHello>(
        reinterpret_cast<LocalHello *>(serialized));
    break;
  }
  return nullptr;
}
