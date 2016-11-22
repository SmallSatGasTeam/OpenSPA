// Utilizes routing table to map logical addresses to IP addresses, including other subnets

#ifndef LOCAL_COMMUNICATOR_HPP
#define LOCAL_COMMUNICATOR_HPP

#include <map>
#include "spa_message.hpp"
#include "spa_physical_communicator.hpp"


// class NetworkCommuncator {
//
// };

struct LogicalAddress {
  LogicalAddress(uint16_t const subId, uint16_t const compId): subnetId(subId), componentId(compId){}
  uint16_t const subnetId;
  uint16_t const componentId;
};

struct LogicalAddressCompare
{
   bool operator() (const LogicalAddress& lhs, const LogicalAddress& rhs) const
   {
     if(lhs.subnetId == rhs.subnetId){
       return lhs.componentId < rhs.componentId;
     } else {
       return lhs.subnetId < rhs.subnetId;
     }
   }
};

class RoutingTable {
public:
  bool insert(LogicalAddress log, uint32_t port){
    routingTable[log] = port;
    return true;
  }

  bool exists(LogicalAddress log){
    if(routingTable.find(log) == routingTable.end()){return false;}
    return true;
  }

  int32_t getPhysicalAddress(LogicalAddress log){
    if(exists(log) == true){ return routingTable[log]; }
    return -1;
  }

protected:
  std::map<LogicalAddress,uint32_t, LogicalAddressCompare> routingTable;
};


class LocalCommunicator: public PhysicalCommunicator{

  bool send(SpaMessage message){
    return false;
  }

  void receive();
  void listen();

};

#endif
