// Utilizes routing table to map logical addresses to IP addresses, including other subnets

#ifndef LOCAL_COMMUNICATOR_HPP
#define LOCAL_COMMUNICATOR_HPP
#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "physical_communicator.hpp"
#include "platform_abstraction/socket/server_socket.hpp"
#include "routing_table.hpp"
#include "spa_message.hpp"

#define SERVER "127.0.0.1"

class LocalCommunicator : public PhysicalCommunicator
{
public:
  LocalCommunicator(
      std::shared_ptr<ServerSocket> sock,
      std::shared_ptr<RoutingTable> routingTable,
      LogicalAddress la) : sock(sock), routingTable(routingTable), PhysicalCommunicator(la) { ; }

  virtual void handleFailure();
  virtual bool sendMsg(std::shared_ptr<SpaMessage> message);

  virtual void listen(PhysicalCommunicator::MessageCallback);

protected:
  std::shared_ptr<RoutingTable> routingTable;
  std::shared_ptr<ServerSocket> sock;
};

#endif
