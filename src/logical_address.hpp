#ifndef LOGICAL_ADDRESS
#define LOGICAL_ADDRESS

#include <cstdint>
#include <vector>

struct LogicalAddress {
  LogicalAddress(uint16_t const subId = 0, uint16_t const compId = 0): subnetId(subId), componentId(compId){}
  uint16_t const subnetId;
  uint16_t const componentId;

  bool isOnSameSubnet(LogicalAddress other){
    return other.subnetId == subnetId;
  }

  std::vector<uint8_t> marshal(){
    // int a[] = {1,2};
    // reinterpret_cast<char*>(a);
    std::vector<uint16_t> address = {subnetId, componentId};
    reinterpret_cast<std::vector <uint8_t> > (address);
  }
};

bool operator==(const LogicalAddress& lhs, const LogicalAddress& rhs){
  return lhs.subnetId == rhs.subnetId && lhs.componentId == rhs.componentId;
}


struct LogicalAddressCompare
{
   bool operator() (const LogicalAddress& lhs, const LogicalAddress& rhs) const
   {
     if(lhs.subnetId == rhs.subnetId){
       return lhs.componentId < rhs.componentId;
     } else {
       return lhs.subnetId < rhs.subnetId;
     }
   }
};

#endif
