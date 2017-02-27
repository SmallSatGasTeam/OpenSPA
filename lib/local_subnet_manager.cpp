#include "local_subnet_manager.hpp"
#include "logical_address.hpp"
#include "spa_message.hpp"
#include "messages/op_codes.hpp"
#include <memory>

void LocalSubnetManager::receiveMessage(std::shared_ptr<SpaMessage> message)
{
  if (message->spaHeader.opcode == op_LOCAL_HELLO)
  {
    components.add(message->spaHeader.source);
  }
}
