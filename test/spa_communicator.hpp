#include <memory>

#include "../lib/spa_communicator.hpp"


void test_test_another(void) {
    TEST_ASSERT_EQUAL(0,0);
}

void spa_communicator_selectCommunicator(void){
  LogicalAddress l1(1,1);
  LogicalAddress l2(2,2);
  LogicalAddress l3(3,3);
  PhysicalCommunicator ph_1(l1), ph_2(l2);
  std::vector<std::shared_ptr <PhysicalCommunicator> > comms;


  comms.push_back(std::make_shared<PhysicalCommunicator>(ph_1));
  comms.push_back(std::make_shared<PhysicalCommunicator>(ph_2));

  SpaCommunicator com(l1);

  std::shared_ptr <PhysicalCommunicator> selected = com.selectCommunicator(l2, comms);
  TEST_ASSERT_TRUE(selected->getSubnetAddress() == l2);

  selected = com.selectCommunicator(l1, comms);
  TEST_ASSERT_TRUE(selected->getSubnetAddress() == l1);

  selected = com.selectCommunicator(l3, comms);
  TEST_ASSERT_TRUE(selected == nullptr);
}

void spa_communicator_send(void){
  LogicalAddress l1(1,1);
  PhysicalCommunicator ph(l1);
  SpaCommunicator com(l1, ph);

}
