#include <logical_address.hpp>

bool operator==(const LogicalAddress& lhs, const LogicalAddress& rhs){
  return lhs.subnetId == rhs.subnetId && lhs.componentId == rhs.componentId;
}
