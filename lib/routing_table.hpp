#ifndef ROUTING_TABLE_HPP
#define ROUTING_TABLE_HPP

#include "logical_address.hpp"
#include <map>

class RoutingTable
{
public:
  bool insert(LogicalAddress log, uint32_t port)
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

  virtual int32_t getPhysicalAddress(LogicalAddress log)
  {
    if (exists(log) == true)
    {
      return routingTable[log];
    }
    return -1;
  }

protected:
  std::map<LogicalAddress, uint32_t, LogicalAddressCompare> routingTable;
};

#endif
