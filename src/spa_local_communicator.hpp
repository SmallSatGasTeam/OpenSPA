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
#include "PA_SOCKET/socket.hpp"

#define SERVER "127.0.0.1"


// class NetworkCommuncator {
//
// };


class LocalCommunicator: public PhysicalCommunicator{
  void handleFailure(){
    std::cout << "Local Communicator failure" << '\n';
    exit(1);
  }

  bool send(Socket const & sock, SpaMessage message){

    int32_t port = routingTable.getPhysicalAddress(message.logicalAddress);
    if(port < 0){ handleFailure(); }
    sock.send(SERVER, port, message.marshal());

    return true;
  }





  void receive();
  void listen();
  LogicalAddress getSubnetAddress(){
    return LogicalAddress(1,0); // Address of local subnet manager TODO figure out how to get this
  }

  RoutingTable routingTable;
  Socket sock;
};

#endif
