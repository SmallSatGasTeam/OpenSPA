#include <memory>

#include "../lib/spa_local_communicator.hpp"


void test_test_another(void) {
    TEST_ASSERT_EQUAL(0,0);
}

// class _SpaCommunicator: public SpaCommunicator {
//   bool _isLocal(){return isLocal(SpaMessage message, LogicalAddress currentAddress, RoutingTable const & routingTable);}
// };
//
// void spa_communicator_isLocal(void){
//   SpaCommunicator com;
//   LogicalAddress current(0,0);
//   SpaMessage localMessage(LogicalAddress(0,1), 1);
//   SpaMessage foreignMessage(LogicalAddress(1,1), 1);
//   RoutingTable rt;
//
//   TEST_ASSERT_TRUE(com.isLocal(localMessage, current, routingTable));
//   // TEST_ASSERT_EQUAL(0,1);
// }

void spa_communicator_selectCommunicator(void){
  LogicalAddress l1(1,1);
  LogicalAddress l2(2,2);
  LogicalAddress l3(3,3);
  PhysicalCommunicator ph_1(l1), ph_2(l2);
  std::vector<std::shared_ptr <PhysicalCommunicator> > comms;


  comms.push_back(std::make_shared<PhysicalCommunicator>(ph_1));
  comms.push_back(std::make_shared<PhysicalCommunicator>(ph_2));
  // SpaMessage message(l3, 1);

  SpaCommunicator com(l1);

  std::shared_ptr <PhysicalCommunicator> selected = com.selectCommunicator(l2, comms);
  TEST_ASSERT_TRUE(selected->getSubnetAddress() == l2);

  selected = com.selectCommunicator(l1, comms);
  TEST_ASSERT_TRUE(selected->getSubnetAddress() == l1);

  selected = com.selectCommunicator(l3, comms);
  TEST_ASSERT_TRUE(selected == nullptr);
}
