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
  void handleFailure();
  bool send(Socket const & sock, SpaMessage message);
  LogicalAddress getSubnetAddress();

  template <typename Func>
  void listen(Func messageHandler);

protected:
  RoutingTable routingTable;
  ServerSocket sock;
};

#endif
