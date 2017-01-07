#include <iostream>
#include <subnet_manager.hpp>
#include <spa_message.hpp>


void SubnetManager::messageCallback(uint8_t* buff, uint32_t len){
  auto message = SpaMessage::unmarshal(buff, len);
  std::cout << "Opcode: " <<(int)message->opcode << '\n';
  return;
}
