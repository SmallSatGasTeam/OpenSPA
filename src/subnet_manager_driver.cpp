#include <iostream>
#include <subnet_manager.hpp>
#include <local_communicator.hpp>

int main(void){
  uint16_t port = 8888;

  std::shared_ptr<ServerSocket> sock = std::make_shared<ServerSocket>();
  sock->bindSocket(port);

  std::shared_ptr<RoutingTable> routingTable = std::make_shared<RoutingTable>();

  LogicalAddress localAddress(1,0);
  std::vector<SpaCommunicator::Com> comms = {
    std::make_shared<LocalCommunicator>(sock, routingTable, localAddress)
  };
  std::shared_ptr<SpaCommunicator> spaCom = std::make_shared<SpaCommunicator>(localAddress, comms);
  SubnetManager manager(spaCom);
  manager.listenMessages();

  return 0;
}
