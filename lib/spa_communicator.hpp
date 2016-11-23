#ifndef SPA_COMMUNICATOR_HPP
#define SPA_COMMUNICATOR_HPP

#include <memory>
#include <vector>
#include <iostream>


#include "spa_message.hpp"
#include "physical_communicator.hpp"
#include "routing_table.hpp"

class SpaCommunicator {
public:

  SpaCommunicator(LogicalAddress currentAddress):currentAddress(currentAddress){;}
  SpaCommunicator(LogicalAddress currentAddress, PhysicalCommunicator const & com)
    :currentAddress(currentAddress){
      communicators.push_back(std::make_shared<PhysicalCommunicator>(com));
    }

  void handleFailure(){
    std::cout << "Spa Communicator Failed" << '\n';
    exit(1);
  }

  std::shared_ptr<PhysicalCommunicator> selectCommunicator(
  LogicalAddress address,
  std::vector<std::shared_ptr <PhysicalCommunicator> > communicators){
    for(auto com : communicators){
      if(com == nullptr){ continue; }
      if(com->getSubnetAddress().isOnSameSubnet(address)){
        return com;
      }
    }
    return nullptr;
  }

  bool send(SpaMessage message){
    std::shared_ptr<PhysicalCommunicator> com = selectCommunicator(
      message.logicalAddress,
      communicators
    );

    if(com == nullptr){
      handleFailure();
      return false;
    }
    com->send(message);
    return true;
  }

  void listen(){
    std::shared_ptr<PhysicalCommunicator> com = selectCommunicator(
      currentAddress,
      communicators
    );

    if(com == nullptr){ handleFailure(); }

    com->listen();
  }


  RoutingTable routingTable;
  LogicalAddress currentAddress;
  std::vector<std::shared_ptr <PhysicalCommunicator> > communicators;
};

#endif
