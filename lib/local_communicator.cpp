#include "local_communicator.hpp"

void LocalCommunicator::handleFailure(){
  //TODO how should this be handled?
  std::cout << "Local Communicator failure" << '\n';
}

bool LocalCommunicator::send(std::shared_ptr<SpaMessage> message){
  if(message == nullptr){ return false; }
  int32_t port = routingTable->getPhysicalAddress(message->logicalAddress);
  if(port < 0){
    handleFailure();
    return false;
  }

  uint8_t* buff = nullptr;
  uint32_t buffLen = message->marshal(buff);
  sock->send(SERVER, port, buff, buffLen);
  return true;
}

void LocalCommunicator::listen(PhysicalCommunicator::MessageCallback messageHandler){
  if(sock == nullptr){
    handleFailure();
    return;
  }
  sock->listen(messageHandler);
}
