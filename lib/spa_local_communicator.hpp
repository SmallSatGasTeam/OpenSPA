// Utilizes routing table to map logical addresses to IP addresses, including other subnets

#ifndef LOCAL_COMMUNICATOR_HPP
#define LOCAL_COMMUNICATOR_HPP
#include <memory>
#include <vector>
#include <map>
#include <iostream>

#include "spa_message.hpp"
#include "physical_communicator.hpp"
#include "routing_table.hpp"


// class NetworkCommuncator {
//
// };

// class ComMap {
// std::map<uin, value> map;
// };


class SpaCommunicator {
public:

  SpaCommunicator(LogicalAddress currentAddress):currentAddress(currentAddress){;}

  void handleFailure(){
    std::cout << "Spa Communicator Failed" << '\n';
    exit(1);
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

  std::shared_ptr<PhysicalCommunicator> selectCommunicator(LogicalAddress address, std::vector<std::shared_ptr <PhysicalCommunicator> > communicators){
    for(auto com : communicators){
      if(com == nullptr){ continue; }
      if(com->getSubnetAddress().isOnSameSubnet(address)){
        return com;
      }
    }
    return nullptr;
  }


  RoutingTable routingTable;
  LogicalAddress currentAddress;
  std::vector<std::shared_ptr <PhysicalCommunicator> > communicators;
};

class LocalCommunicator: public PhysicalCommunicator{
  //NOTE: Physical Communicator knows what subnet it communicates on
  //maybe getSubnet method?
  bool send(SpaMessage message){
    // If we have logical address route to component
    // Otherwise send to other subnet manager

    return false;
  }

  void receive();
  void listen();
  LogicalAddress getSubnetAddress(){
    return LogicalAddress(0,1); // Address of local subnet manager
  }
};

#endif
