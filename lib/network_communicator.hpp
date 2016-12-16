#ifndef NETWORK_COMMUNICATOR_HPP
#define NETWORK_COMMUNICATOR_HPP
#include <memory>
#include <vector>

#include "spa_communicator.hpp"
#include "local_communicator.hpp"
class NetworkCommunicator {
public:
  NetworkCommunicator(LogicalAddress la):spaCom(la), localCom(la){
    std::vector<SpaCommunicator::Com> comms;
    comms.push_back(std::make_shared<PhysicalCommunicator>(localCom));
    spaCom.addCommunicators(comms);
  }

  SpaCommunicator spaCom;
  LocalCommunicator localCom;
};
#endif
