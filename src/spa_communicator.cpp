#include <iostream>

#include <spa_communicator.hpp>

SpaCommunicator::SpaCommunicator(LogicalAddress currentAddress):currentAddress(currentAddress){}
SpaCommunicator::SpaCommunicator(LogicalAddress currentAddress, PhysicalCommunicator const & com)
  :currentAddress(currentAddress){
    communicators.push_back(std::make_shared<PhysicalCommunicator>(com));
  }

SpaCommunicator::SpaCommunicator(LogicalAddress currentAddress, std::vector<Com> comms)
:currentAddress(currentAddress){ addCommunicators(comms); }

void SpaCommunicator::addCommunicators(std::vector<SpaCommunicator::Com> comms){
  communicators.insert(communicators.end(), comms.begin(), comms.end());
}

void SpaCommunicator::handleFailure(){
  std::cout << "Spa Communicator Failed" << '\n';
  exit(1);
}

 SpaCommunicator::Com SpaCommunicator::selectCommunicator(
  LogicalAddress address,
  std::vector<Com> const & communicators){
    for(auto com : communicators){
      if(com == nullptr){ continue; }
      if(com->getSubnetAddress().isOnSameSubnet(address)){
        return com;
      }
    }
    return nullptr;
  }


  bool SpaCommunicator::send(SpaMessage message){
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

//TODO document
template <typename Func>
void SpaCommunicator::listen(Func messageHandler){
    std::shared_ptr<PhysicalCommunicator> com = selectCommunicator(
      currentAddress,
      communicators
    );

    if(com == nullptr){ handleFailure(); }

    com->listen(messageHandler);
  }
