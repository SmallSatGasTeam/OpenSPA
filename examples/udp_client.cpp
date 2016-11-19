/*
    Simple udp client
*/
#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);

#include<arpa/inet.h>
// #include<sys/socket.h>
// #include <sys/types.h>
// #include <netinet/in.h>


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
#include <unistd.h>
#include <cerrno>

#include <cstdint>
#include <string>
#include <iostream>

#define SERVER "127.0.0.1"
#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to send data

void die(char *s)
{
    perror(s);
    exit(1);
}

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

//__________

class Socket{
public:
  Socket():fd(-1){
    if(init() == false){
      handleFailure();
    }
  }

  ~Socket(){
    if(fd >= 0) {close(fd);}
  }

  bool send(std::string address, uint16_t port, std::string message){

    if(fd < 1){ handleFailure(); }

    SocketAddress addr(address, port);
    struct sockaddr_in saddr = addr.to_sockaddr_in();
    int8_t result = sendto(
      fd,
      message.c_str(),
      strlen(message.c_str()),
      0,
      (struct sockaddr *) &saddr,
      sizeof(saddr)
    );

    if(result == -1) {
      handleFailure();
      return false;
    }
    return true;
  }
  // void bind();

protected:
  bool init(){
    if ( (fd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
      return false;
    }
    return true;
  }

  void handleFailure(){
    // TODO not sure how to die just yet :)
    std::cout << "Socket Failure" << std::endl;
    exit(1);
  }

  int32_t fd;
};


int main(void)
{
    Socket s;

    while(true){
      std::string message;
      std::cout << "Enter message to send: " << std::endl;
      std::cin >> message;
      bool result = s.send(SERVER, PORT, message);
      if(result) {
        std::cout << "Message successfully sent" << std::endl;
        std::cout << "Message: " << message << std::endl;
      } else {
        std::cout << "Message was not sent..." << std::endl;
      }
    }

    return 0;
}


/*
    Simple udp client
*/
// #include<stdio.h> //printf
// #include<string.h> //memset
// #include<stdlib.h> //exit(0);
// #include<arpa/inet.h>
// #include<sys/socket.h>
//
// #define SERVER "127.0.0.1"
// #define BUFLEN 512  //Max length of buffer
// #define PORT 8888   //The port on which to send data
//
// void die(char *s)
// {
//     perror(s);
//     exit(1);
// }
//
// int main(void)
// {
//     struct sockaddr_in si_other;
//     int s, i, slen=sizeof(si_other);
//     char buf[BUFLEN];
//     char message[BUFLEN];
//
//     if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
//     {
//         die("socket");
//     }
//
//     memset((char *) &si_other, 0, sizeof(si_other));
//     si_other.sin_family = AF_INET;
//     si_other.sin_port = htons(PORT);
//
//     if (inet_aton(SERVER , &si_other.sin_addr) == 0)
//     {
//         fprintf(stderr, "inet_aton() failed\n");
//         exit(1);
//     }
//
//     while(1)
//     {
//         printf("Enter message : ");
//         gets(message);
//
//         //send the message
//         if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen)==-1)
//         {
//             die("sendto()");
//         }
//
//         //receive a reply and print it
//         //clear the buffer by filling null, it might have previously received data
//         memset(buf,'\0', BUFLEN);
//         //try to receive some data, this is a blocking call
//         if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == -1)
//         {
//             die("recvfrom()");
//         }
//
//         puts(buf);
//     }
//
//     close(s);
//     return 0;
// }
