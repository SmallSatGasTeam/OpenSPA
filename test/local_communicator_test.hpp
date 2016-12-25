
#include "mocks/platform_abstraction/socket/server_socket.hpp"
#include <local_communicator.hpp>
#include <routing_table.hpp>

TEST(LocalCommunicator, send__address_exists_in_table){
  std::shared_ptr<MockServerSocket> sock = std::make_shared<MockServerSocket>();
  std::shared_ptr<RoutingTable> rt = std::make_shared<RoutingTable>();
  LogicalAddress la(1,1);
  rt->insert(la, 2);
  SpaMessage message(la, 0);

  LocalCommunicator lc(
    sock,
    rt,
    la
  );

  EXPECT_CALL(*sock, send(SERVER, 2, nullptr, 0)).Times(1);

  lc.send(message);
}

// TEST(LocalCommunicator, send__not_in_table){}
// TEST(LocalCommunicator, listen){}
