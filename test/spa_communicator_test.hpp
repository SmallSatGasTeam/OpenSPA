#include <memory>

#include <spa_communicator.hpp>

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
