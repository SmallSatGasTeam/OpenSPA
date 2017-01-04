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
  std::cout << (int)msg->opcode << '\n';

  switch (msg->messageType) {
    case SpaMessage::TEST_TYPE:
    uint8_t buff[512];
    auto cpy = memcpy(buff, serialized, size);
    auto message = new(cpy) TestDerivedMessage;
    // MyObject *obj = new(bytes) MyObject;


    // message = reinterpret_cast<TestDerivedMessage*>(cpy);
    // std::cout << (int)message->opcode << '\n';
    // auto ptr = std::shared_ptr<TestDerivedMessage>(message);
      // return std::shared_ptr<TestDerivedMessage>(
        // reinterpret_cast<TestDerivedMessage*>(serialized)
        // message
      // );
    break;
  }
  return nullptr;
}

// uint8_t const SpaMessage::TEST_TYPE = 1;
