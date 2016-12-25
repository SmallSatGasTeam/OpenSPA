
#include "mocks/platform_abstraction/socket/server_socket.hpp"
#include <local_communicator.hpp>
#include <routing_table.hpp>

class LocalCommunicatorTest : public ::testing::Test {
public:
  virtual void SetUp(){
    opcode = 0;
    port = 9;
    addr = std::make_shared<LogicalAddress>(1,1);
    fullTable->insert(*addr, port);
    message = std::make_shared<SpaMessage>(*addr, 0);
  }


  std::shared_ptr<RoutingTable> fullTable;
  std::shared_ptr<RoutingTable> emptyTable;
  std::shared_ptr<LogicalAddress> addr;
  std::shared_ptr<SpaMessage> message;
  uint16_t port;
  uint8_t opcode;
};


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

TEST(LocalCommunicator, send__not_in_table){

}
// TEST(LocalCommunicator, listen){}
