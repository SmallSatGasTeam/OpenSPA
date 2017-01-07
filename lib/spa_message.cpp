#include <iostream>
#include <cstring>

#include "spa_message.hpp"
#include "messages/test_type.hpp"

//TODO document
uint32_t SpaMessage::marshal(uint8_t* target){
  if(target == nullptr){ return 0; }
  uint32_t length = sizeof(*this);
  memcpy(target, reinterpret_cast<uint8_t*>(this), length);
  return length;
}

std::shared_ptr<SpaMessage> SpaMessage::unmarshal(uint8_t* serialized, uint32_t size){
  auto msg = reinterpret_cast<SpaMessage*>(serialized);
  switch (msg->messageType) {
    case SpaMessage::TEST_TYPE:
      return std::shared_ptr<TestDerivedMessage>(
        reinterpret_cast<TestDerivedMessage*>(serialized)
      );
    break;
  }
  return nullptr;
}

// uint8_t const SpaMessage::TEST_TYPE = 1;
