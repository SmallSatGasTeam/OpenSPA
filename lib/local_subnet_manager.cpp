#include "local_subnet_manager.hpp"
#include "spa_message.hpp"
#include "logical_address.hpp"

void LocalSubnetManager::receiveMessage(SpaMessage message) 
{
  if (message.spaHeader.opcode == 0x20)
  {
    components.add(message.spaHeader.source);
  }
}
    
