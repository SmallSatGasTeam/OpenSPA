#include <iostream>
#include <component.hpp>
#include <messages/test_type.hpp>
#include <local_communicator.hpp>

class ExampleComponent: public Component{
public:
  ExampleComponent(Component::Com com = nullptr):Component(com){}

  virtual void appInit(){
    std::cout << "Example app initializing!" << '\n';
    std::shared_ptr<TestDerivedMessage> message
      = std::make_shared<TestDerivedMessage>(LogicalAddress(1,3), 5);
    sendMsg(message);
  }
};


int main(){
  uint16_t port = 8888;
  std::shared_ptr<ServerSocket> sock = std::make_shared<ServerSocket>();
  std::shared_ptr<RoutingTable> routingTable = std::make_shared<RoutingTable>();
  routingTable->insert(LogicalAddress(1,3), 8888);

  LogicalAddress localAddress(1,0);
  std::vector<SpaCommunicator::Com> comms = {
    std::make_shared<LocalCommunicator>(sock, routingTable, localAddress)
  };
  std::shared_ptr<SpaCommunicator> spaCom = std::make_shared<SpaCommunicator>(localAddress, comms);

  ExampleComponent comp(spaCom);
  comp.appInit();
  return 0;
}
