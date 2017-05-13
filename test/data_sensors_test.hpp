#include "mocks/spa_communicator.hpp"
#include <messages/spa_data.hpp>
#include <components/data_sensors.hpp>
#include <string>

class DataSensorsTest : public ::testing::Test
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
  }
  std::shared_ptr<SpaCommunicator> spaCommunicator;
  std::shared_ptr<LogicalAddress> addr;
};


TEST_F(DataSensorsTest, packageReset)
{
  LogicalAddress destination(0, 1);

  std::shared_ptr<DataSensors> sensors = std::make_shared<DataSensors>(spaCommunicator, *addr);
  std::vector<std::string> pkg = { "8", "no", "test", "hey", "42.2", "20", "lol", "x" };
  sensors->setDataPackage(pkg);
  sensors->sendSpaData(destination);

  std::vector<std::string> newPack(8, "x");
  EXPECT_EQ(newPack, sensors->getDataPackage());


}

