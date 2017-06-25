#ifndef ROUTING_TABLE_HPP
#define ROUTING_TABLE_HPP

#include "logical_address.hpp"
#include <map>
#include <iostream>



class RoutingTable
{
public:

  RoutingTable(LogicalAddress log, uint16_t port){ if (!insert(log, port)) std::cerr << "Routing Table Construction Failure." << std::endl; }

  bool insert(LogicalAddress log, uint16_t port)
  {
    routingTable[log] = port;
    return true;
  }

  bool exists(LogicalAddress log)
  {
    if (routingTable.find(log) == routingTable.end())
    {
      return false;
    }
    return true;
  }

  uint16_t getPhysicalAddress(LogicalAddress log)
  {
    if (exists(log) == true)
    {
      return routingTable[log];
    }
    return -1;
  }

protected:
  std::map<LogicalAddress, uint16_t, LogicalAddressCompare> routingTable;
};

#endif
