
#ifndef PHYSICAL_COMMUNICATOR_HPP
#define PHYSICAL_COMMUNICATOR_HPP

#include "logical_address.hpp"
#include "spa_message.hpp"

  class PhysicalCommunicator {
  public:
    PhysicalCommunicator(LogicalAddress la):subnetAddress(la){}

    virtual ~PhysicalCommunicator(){}
    virtual bool send(SpaMessage message){ return false; }
    virtual void listen(void(*messageHandler)(uint8_t* buff, uint32_t bufflen)){}

    LogicalAddress getSubnetAddress(){ return subnetAddress; }

    
    LogicalAddress subnetAddress;
  };
#endif
