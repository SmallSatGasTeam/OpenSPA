#include <iostream>
#include <subnet_manager.hpp>

void messageCallback(uint8_t*, uint32_t){
  std::cout << "Recieved Message!" << '\n';
  return;
}
