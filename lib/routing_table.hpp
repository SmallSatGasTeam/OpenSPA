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
    routingTable.insert(std::pair<LogicalAddress, uint16_t>(log,port));
    //routingTable[log] = port;
    return true;
  }

  bool exists(LogicalAddress log)
  {
    std::map<LogicalAddress, uint16_t,LogicalAddressCompare>::iterator i = routingTable.begin();
	for (i = routingTable.begin(); i != routingTable.end(); i++)
	{
		if (i->first == log){
	std::cout << "(RoutingTable::exists)Found Address with port" << i->second << std::endl;
	return true;
	}
	}
	return false;
}

/*
    if (routingTable.find(log) == routingTable.end())
    {
      return false;
    }
    return true;
  }
*/

<<<<<<< HEAD
  virtual int32_t getPhysicalAddress(LogicalAddress log)
=======
  uint16_t getPhysicalAddress(LogicalAddress log)
>>>>>>> 33800320f8192fb2649e470c0bf30e26b4e2427f
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
