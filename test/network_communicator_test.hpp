#include <network_communicator.hpp>

TEST(NetworkCommunicator, NetworkCommunicator)
{
  LogicalAddress la(1, 1);
  NetworkCommunicator netCom(la);
}
