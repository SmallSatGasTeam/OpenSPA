#include <iostream>
#include <spa_message.hpp>
#include <messages/op_codes.hpp>
#include <messages/local/local_ack.hpp>
#include <subnet_manager.hpp>
#include <memory>


std::shared_ptr<SpaCommunicator> SubnetManager::communicator;

void SubnetManager::messageCallback(uint8_t *buff, uint32_t len)
{
  auto message = SpaMessage::unmarshal(buff, len);

  std::cout << "Opcode: " << (int)message->spaHeader.opcode << '\n';

  if (op_LOCAL_HELLO == message->spaHeader.opcode)
  {
    auto msg = std::make_shared<LocalAck>(
      0,
      0,
      message->spaHeader.source,
      message->spaHeader.destination,
      0,
      42,
      0
      );

    communicator->send(msg);
  }

  return;
}
