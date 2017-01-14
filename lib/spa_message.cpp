#include <cstring>
#include <iostream>

#include <messages/test_derived_message.hpp>
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
  case SpaMessage::TEST_TYPE:
    return std::shared_ptr<TestDerivedMessage>(
        reinterpret_cast<TestDerivedMessage *>(serialized));
    break;
  }
  return nullptr;
}
