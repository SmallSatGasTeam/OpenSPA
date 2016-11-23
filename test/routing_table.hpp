#include <vector>
#include <map>
#include <cstdint>
#include "../lib/routing_table.hpp"

/**
 *  Sub class with added testing functionality
 */
class _RoutingTable : public RoutingTable {
public:
  std::map<LogicalAddress, uint32_t, LogicalAddressCompare> getTable(){return routingTable;}
};


void routing_table_insert(void) {
  _RoutingTable rt;
  LogicalAddress l1(1,1);
  LogicalAddress l2(2,2);
  LogicalAddress l3(1,2);
  LogicalAddress l4(0,0);

  rt.insert(l1, 1);
  rt.insert(l2, 2);
  rt.insert(l3, 3);

  std::map<LogicalAddress, uint32_t, LogicalAddressCompare> table = rt.getTable();

  TEST_ASSERT_EQUAL(table[l1], 1);
  TEST_ASSERT_EQUAL(table[l2], 2);
  TEST_ASSERT_EQUAL(table[l3], 3);

  // Should return iterator to end if key does not exist in map
  TEST_ASSERT_TRUE(table.find(l4) == table.end());
}

void routing_table_exists(void){
  _RoutingTable rt;
  LogicalAddress l1(1,1);
  LogicalAddress l2(2,1);
  rt.insert(l1, 1);

  TEST_ASSERT_TRUE(rt.exists(l1));
  TEST_ASSERT_FALSE(rt.exists(l2));
}

void routing_table_get_physical_address(void){
  _RoutingTable rt;
  LogicalAddress l1(1,1);
  LogicalAddress l2(1,2);
  rt.insert(l1, 9);

  TEST_ASSERT_EQUAL(rt.getPhysicalAddress(l1), 9);
  TEST_ASSERT_EQUAL(rt.getPhysicalAddress(l2), -1);
}
