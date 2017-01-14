#include <iostream>
#include <spa_message.hpp>
#include <subnet_manager.hpp>

void SubnetManager::messageCallback(uint8_t *buff, uint32_t len)
{
  auto message = SpaMessage::unmarshal(buff, len);
  std::cout << "Opcode: " << (int)message->spaHeader.opcode << '\n';
  return;
}
