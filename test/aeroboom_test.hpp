#include "mocks/spa_communicator.hpp"
#include <messages/spa_data.hpp>
#include <components/aeroboom.hpp>
#include <string>

class AeroboomTest : public ::testing::Test
{
public:
  virtual void SetUp()
  {
    uint16_t port = 8888;
    std::shared_ptr<ServerSocket> sock = std::make_shared<ServerSocket>();
    std::shared_ptr<RoutingTable> routingTable = std::make_shared<RoutingTable>();
    routingTable->insert(LogicalAddress(1, 3), 8888);
    LogicalAddress localAddress(1, 0);
    std::vector<SpaCommunicator::Com> comms = {
        std::make_shared<LocalCommunicator>(sock, routingTable, localAddress)};
    spaCommunicator = std::make_shared<SpaCommunicator>(localAddress, comms);
    addr = std::make_shared<LogicalAddress>(0, 0);
    boom = std::make_shared<Aeroboom>(spaCommunicator, *addr);
  }
  std::shared_ptr<SpaCommunicator> spaCommunicator;
  std::shared_ptr<LogicalAddress> addr;
  std::shared_ptr<Aeroboom> boom;
};

TEST_F(AeroboomTest, deployment)
{
  LogicalAddress destination(0, 1);

  std::string payload = "deploy";

  auto msg = std::make_shared<SpaData<std::string>>(
      0,     // version
      0,     // priority
      *addr, // source
      destination,
      0,
      0, // sequeceIndex
      0, // sequenceCount
      0, // xTEDS interface ID
      0, // xTEDS messageID
      payload);

  EXPECT_NO_FATAL_FAILURE(boom->handleSpaData(msg));
}
