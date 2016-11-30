#include <local_communicator.hpp>

void LocalCommunicator::handleFailure(){
  std::cout << "Local Communicator failure" << '\n';
  exit(1);
}

bool LocalCommunicator::send(Socket const & sock, SpaMessage message){
  int32_t port = routingTable.getPhysicalAddress(message.logicalAddress);
  if(port < 0){ handleFailure(); }
  // sock.send(SERVER, port, message.marshal());
  return true;
}


void LocalCommunicator::listen(void(*messageHandler)(uint8_t* buff, uint32_t bufflen)){
  sock.listen(messageHandler);
}

LogicalAddress getSubnetAddress(){
  return LogicalAddress(1,0);
}
