#include <iostream>
#include <subnet_manager.hpp>

void SubnetManager::messageCallback(uint8_t *buff, uint32_t len)
{
  for (int i = 0; i < len; i++)
  {
    std::cout << buff[i];
  }
  std::cout << '\n';
  return;
}
