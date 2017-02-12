#include "local_subnet_manager.hpp"
#include "logical_address.hpp"
#include "spa_message.hpp"
#include <memory>

void LocalSubnetManager::receiveMessage(std::shared_ptr<SpaMessage> message)
{
  if (message->spaHeader.opcode == 0x20)
  {
    components.add(message->spaHeader.source);
  }
}
