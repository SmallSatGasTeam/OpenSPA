// Utilizes routing table to map logical addresses to IP addresses, including other subnets

#ifndef LOCAL_COMMUNICATOR_HPP
#define LOCAL_COMMUNICATOR_HPP

#include "spa_message.hpp"
#include "spa_physical_communicator.hpp"


// class NetworkCommuncator {
//
// };


class LocalCommunicator: public PhysicalCommunicator{

  bool send(SpaMessage message){
    return false;
  }

  void receive();
  void listen();

};

#endif
