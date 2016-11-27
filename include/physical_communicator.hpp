
#ifndef PHYSICAL_COMMUNICATOR_HPP
#define PHYSICAL_COMMUNICATOR_HPP

#include "logical_address.hpp"
#include "spa_message.hpp"
  
  class PhysicalCommunicator {
  public:
    PhysicalCommunicator(){}
    PhysicalCommunicator(LogicalAddress la):subnetAddress(la){}

    virtual bool send(SpaMessage message){ return false; }
    virtual void listen(){}

    virtual LogicalAddress getSubnetAddress(){
      return subnetAddress;
    }

    LogicalAddress subnetAddress;
  };
#endif
