/*
    Simple udp server
*/


#include "../lib/PA_Socket/server_socket.hpp"

#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data


int main(void)
{
  ServerSocket s;

  s.bindSocket(PORT);
  s.listen();
  return 0;
}
