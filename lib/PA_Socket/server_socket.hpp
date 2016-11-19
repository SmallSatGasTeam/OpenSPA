#ifndef SERVER_SOCKET_HPP
#define SERVER_SOCKET_HPP
#include<stdio.h> //printf
#include<string.h> //memset

#include "socket.hpp"

#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data


class ServerSocket: public Socket{
public:
  ServerSocket():Socket(){}

  bool bindSocket(uint32_t port){
    //TODO check fd for errors

    SocketAddress addr("", port);
    struct sockaddr_in si_me = addr.to_sockaddr_in();
    if( bind(fd , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1){
      handleFailure();
      return false;
    }
    return true;
  }

  
  void listen(){
    //TODO check fd for errors
    uint8_t buf[BUFLEN];

    SocketAddress addr;
    struct sockaddr_in si_other = addr.to_sockaddr_in();

    for(;;){
      memset(buf, 0, BUFLEN);
      printf("Waiting for data...");
      fflush(stdout);

      uint32_t addr_len = sizeof(si_other);

      //try to receive some data, this is a blocking call
      size_t result = recvfrom(
        fd,
        buf,
        BUFLEN,
        0,
        (struct sockaddr *) &si_other,
        &addr_len
      );

      if (result == -1) {
        handleFailure();
      }


      // //print details of the client/peer and the data received
      printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
      printf("Data: %s\n" , buf);

      // //now reply the client with the same data
      // if (sendto(fd, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == -1)
      // {
      //   handleFailure();
      // }
    }
}

};
#endif
