// Utilizes routing table to map logical addresses to IP addresses, including other subnets

#ifndef LOCAL_COMMUNICATOR_HPP
#define LOCAL_COMMUNICATOR_HPP
#include <memory>
#include <vector>
#include <map>
#include <iostream>

#include "spa_message.hpp"
#include "physical_communicator.hpp"
#include "routing_table.hpp"
#include "platform_abstraction/socket/server_socket.hpp"

#define SERVER "127.0.0.1"

class LocalCommunicator: public PhysicalCommunicator{
public:
  // LocalCommunicator():PhysicalCommunicator(){;}

  // void handleFailure();
  // bool send(SpaMessage message){ return false; }
  // bool send(Socket const & sock, SpaMessage message);
  // LogicalAddress getSubnetAddress();
  //
  // // void listen(Func messageHandler);
  // virtual void listen(void(*messageHandler)(uint8_t* buff, uint32_t bufflen));

protected:
  // RoutingTable routingTable;
  // ServerSocket sock;
};

#endif
