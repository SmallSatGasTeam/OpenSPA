#ifndef LOGICAL_ADDRESS
#define LOGICAL_ADDRESS

struct LogicalAddress {
  LogicalAddress(uint16_t const subId, uint16_t const compId): subnetId(subId), componentId(compId){}
  uint16_t const subnetId;
  uint16_t const componentId;
};

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
