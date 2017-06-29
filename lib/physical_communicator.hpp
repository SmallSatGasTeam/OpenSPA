
#ifndef PHYSICAL_COMMUNICATOR_HPP
#define PHYSICAL_COMMUNICATOR_HPP

#include <functional>

#include "logical_address.hpp"
#include "spa_message.hpp"

class PhysicalCommunicator
{
public:
  typedef void (*MessageCallback)(uint8_t *, uint32_t);

  PhysicalCommunicator(LogicalAddress la) : subnetAddress(la) {}

  virtual ~PhysicalCommunicator() {}
  virtual bool sendMsg(std::shared_ptr<SpaMessage> message) { return false; }
  virtual void listen(std::function<void(uint8_t *, uint32_t)>) {}

  virtual LogicalAddress getSubnetAddress() { return subnetAddress; }

  virtual void insertToRoutingTable(LogicalAddress, uint32_t){};

  LogicalAddress subnetAddress;
};
#endif
