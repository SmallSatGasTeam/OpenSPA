//Handle health checks
//Handle componenet registration

#ifndef LOCAL_SUBNET_MANAGER
#define LOCAL_SUBNET_MANAGER

#include "component_list.hpp"
#include "subnet_manager.hpp"
#include <cstdint>

class LocalSubnetManager : public SubnetManager
{
public:
  LocalSubnetManager(std::shared_ptr<SpaCommunicator> c) : SubnetManager(c) {}
  void receiveMessage(std::shared_ptr<SpaMessage> message);
  // receiveMessage(uint8_t *buff, uint32_t bufflen);
  ComponentList components;
};
#endif
