#include "local_communicator.hpp"

void LocalCommunicator::handleFailure(){
  //TODO how should this be handled?
  std::cout << "Local Communicator failure" << '\n';
}

bool LocalCommunicator::send(SpaMessage message){
  int32_t port = routingTable->getPhysicalAddress(message.logicalAddress);
  if(port < 0){
    handleFailure();
    return false;
  }

  uint8_t* buff = nullptr;
  uint32_t buffLen = message.marshal(buff);
  sock->send(SERVER, port, buff, buffLen);
  return true;
}

void LocalCommunicator::listen(void(*messageHandler)(uint8_t* buff, uint32_t bufflen)){
  sock->listen(messageHandler);
}

LogicalAddress LocalCommunicator::getSubnetAddress(){
  // Local communicators are always on the local subnet(address 1)
  return LogicalAddress(1,0);
}
