#include <iostream>
#include <cstring>

#include "spa_message.hpp"

//TODO document
uint32_t SpaMessage::marshal(uint8_t* target){
  uint32_t length = sizeof(*this);
  memcpy(target, reinterpret_cast<uint8_t*>(this), length);
  return length;
}
