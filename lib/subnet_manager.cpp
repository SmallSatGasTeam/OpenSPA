#include <iostream>
#include <spa_message.hpp>
#include <subnet_manager.hpp>
#include <messages/op_codes.hpp>
#include <messages/local/local_ack.hpp>
#include <memory>
#include <messages/local/local_spa_message.hpp>
#include <messages/local/local_hello.hpp>

std::shared_ptr<SpaCommunicator> SubnetManager::communicator;

void SubnetManager::messageCallback(uint8_t *buff, uint32_t len)
{
  auto message = LocalSpaMessage::unmarshal(buff, len);
  std::cout << "Opcode: " << (int)message->spaHeader.opcode << '\n';
  
  if(op_LOCAL_HELLO == message->spaHeader.opcode)
  {
	auto castMessage = std::dynamic_pointer_cast<LocalHello>(message); 
	routingTable->insert(message->spaHeader.source, castMessage->spaLocalHeader.sourcePort);		


	  auto msg = std::make_shared<LocalAck>(
	  0,
	  0,
	  message->spaHeader.destination,
	  message->spaHeader.source,
	  0,
	  8888,
	  0);
	 
	 
	  if(msg == nullptr || communicator == nullptr)
	  {
		  std::cout << "bad things, aborting." << std::endl;
	  }
	  else
	  {
		  std::cout << "Sending message." << std::endl;
	      communicator->send(msg);
	  }

  }
  
  
  return;



}
