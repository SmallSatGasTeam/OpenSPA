#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "spa_communicator.hpp"
#include <memory>

class Component
{
public:
  typedef std::shared_ptr<SpaCommunicator> Com;

  Component(Com communicator = nullptr, LogicalAddress address) : 
    communicator(communicator),
    address(address)
    dialogId(0) {}
  // virtual ~Component(){}
  virtual void appInit() = 0;
  // virtual void appShutdown();
  // virtual int32_t publish();

  template <typename M>
  virtual void registerSubscriptionRequest(M);

  template <typename M>
  virtual void sendMsg(M);

  template <typename M>
  virtual void receiveMessage(M); 

  template <typename M>
  virtual void handleSubscriptionReply(M);

  virtual void subscribe(
    LogicalAddress producer,
    uint8_t priority,
    uint32_t leasePeriod,
    uint16_t deliveryRateDivisor
    );


protected:
  LogicalAddress address;
  Com communicator;
private:
  uint16_t dialogId;
};
#endif
