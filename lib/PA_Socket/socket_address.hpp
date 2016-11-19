#ifndef SOCKET_ADDRESS_HPP
#define SOCKET_ADDRESS_HPP

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
#include <unistd.h>
#include <cerrno>

#include <cstdint>
#include <string>
#include <iostream>


class SocketAddress{
public:
  SocketAddress(std::string addr = "", int port = -1): address(addr), port(port){}
  void handleFailure(){
    std::cout << "Socket Address Failure" << std::endl;
    exit(1);
  }

  struct sockaddr_in to_sockaddr_in() {
    struct sockaddr_in addr;
		memset(&addr, 0, sizeof addr);

		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);

		if(inet_aton(address.c_str(), &addr.sin_addr) == 0){
      handleFailure();
    }

		return addr;
  }
protected:
  std::string address;
  int port;
};

#endif
