#include <spa_communicator.hpp>

#include "mocks/local_communicator.hpp"

class SpaCommunicatorTest : public ::testing::Test {
public:
  virtual void SetUp(){
    comms.push_back(
      localCom = std::make_shared<MockLocalCommunicator>(LogicalAddress(1,0)));
    comms.push_back(
      foreignCom = std::make_shared<MockLocalCommunicator>(LogicalAddress(2,0)));

    localMessage = std::make_shared<SpaMessage>(LogicalAddress(1,1), 1);
    foreignMessage = std::make_shared<SpaMessage>(LogicalAddress(2,1), 1);
    nonConnectedMessage = std::make_shared<SpaMessage>(LogicalAddress(3,1), 1);
  }

  std::shared_ptr<MockLocalCommunicator> localCom;
  std::shared_ptr<MockLocalCommunicator> foreignCom;
  std::vector<SpaCommunicator::Com> comms;
  std::shared_ptr<SpaMessage> localMessage;
  std::shared_ptr<SpaMessage> foreignMessage;
  std::shared_ptr<SpaMessage> nonConnectedMessage;
};

TEST_F(SpaCommunicatorTest, send__to_same_network){
  SpaCommunicator spaCom(LogicalAddress(1,0), comms);
  EXPECT_CALL(*localCom, send(localMessage)).Times(1);

  bool result = spaCom.send(localMessage);
  EXPECT_TRUE(result);
}

TEST_F(SpaCommunicatorTest, send__to_other_network){
  SpaCommunicator spaCom(LogicalAddress(1,0), comms);
  EXPECT_CALL(*foreignCom, send(foreignMessage)).Times(1);

  bool result = spaCom.send(foreignMessage);
  EXPECT_TRUE(result);
}


// TEST(SpaCommunicatorTest, listen){}


class _SpaCommunicator: public SpaCommunicator {
public:
  _SpaCommunicator(LogicalAddress currentAddress):SpaCommunicator(currentAddress){}
  Com _selectCommunicator(LogicalAddress address, std::vector<Com> const & communicators){
    return selectCommunicator(address, communicators);
  }
};

TEST(SpaCommunicator, selectCommunicator){
  LogicalAddress l1(1,1);
  LogicalAddress l2(2,2);
  LogicalAddress l3(3,3);
  PhysicalCommunicator ph_1(l1), ph_2(l2);
  std::vector<std::shared_ptr <PhysicalCommunicator> > comms;


  comms.push_back(std::make_shared<PhysicalCommunicator>(ph_1));
  comms.push_back(std::make_shared<PhysicalCommunicator>(ph_2));

  _SpaCommunicator com(l1);

  std::shared_ptr <PhysicalCommunicator> selected = com._selectCommunicator(l2, comms);
  EXPECT_TRUE(selected->getSubnetAddress() == l2);

  selected = com._selectCommunicator(l1, comms);
  EXPECT_TRUE(selected->getSubnetAddress() == l1);

  selected = com._selectCommunicator(l3, comms);
  EXPECT_TRUE(selected == nullptr);
}
