//Handle health checks
//Handle componenet registration

#ifndef LOCAL_SUBNET_MANAGER
#define LOCAL_SUBNET_MANAGER

#include <cstdint>
#include "subnet_manager.hpp"

class LocalSubnetManager: public SubnetManager {
public: 
  recieveMessage(SpaMessage message;);
  recieveMessage(uint8_t* buff, uint32_t bufflen);


};
#endif
