#include "local_subnet_manager.hpp"
#include "logical_address.hpp"
#include "spa_message.hpp"
#include "messages/op_codes.hpp"
#include "messages/local/local_ack.hpp"
#include <memory>

void LocalSubnetManager::receiveMessage(std::shared_ptr<SpaMessage> message)
{
  if (message->spaHeader.opcode == op_LOCAL_HELLO)
  {
    components.add(message->spaHeader.source);
    std::shared_ptr<LocalAck> messageAck = std::make_shared<LocalAck>(
	0,
	0,
	message->spaHeader.source, 
	message->spaHeader.destination,
	0,
	42,//TODO: MAKE REAL sourcePort
	0); //TODO: add a real status

    communicator->send(messageAck); 
  }
}
