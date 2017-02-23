#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "messages/spa_subscription_reply.hpp"
#include "messages/spa_subscription_request.hpp"
#include "spa_communicator.hpp"
#include "spa_message.hpp"
#include <iostream>
#include <memory>
#include <vector>

struct Subscriber
{
  Subscriber(LogicalAddress la, uint16_t d)
    : subscriberAddress(la), deliveryRateDivisor(d) {}
  LogicalAddress subscriberAddress;
  uint16_t deliveryRateDivisor;
};

class Component
{
public:
  typedef std::shared_ptr<SpaCommunicator> Com;

  Component(Com communicator = nullptr, LogicalAddress address = LogicalAddress(0, 0)) 
    : communicator(communicator),
      address(address),
      dialogId(0),
      publishIter(1)
      
      {
        subscribers.reserve(8); // Default to 8 subscribers 
      }

  virtual ~Component() {}
  virtual void appInit() = 0;
  // virtual void appShutdown();
  
  virtual void publish();
  virtual void sendSpaData(LogicalAddress) = 0;

  template <typename M>
  void sendMsg(M);

  virtual void receiveMessage(std::shared_ptr<SpaMessage>);

  virtual void handleSubscriptionReply(std::shared_ptr<SpaMessage>);
  virtual void registerSubscriptionRequest(std::shared_ptr<SpaMessage>);

  virtual void handleSpaData(std::shared_ptr<SpaMessage>) = 0;

  virtual void subscribe(
      LogicalAddress producer,
      uint8_t priority,
      uint32_t leasePeriod,
      uint16_t deliveryRateDivisor);

protected:
  LogicalAddress address;
  Com communicator;
  uint8_t publishIter;
  uint16_t dialogId;
  std::vector<Subscriber> subscribers; // Should we make this a vector of pointers?
};

template <typename M>
void Component::sendMsg(M message)
{
  if (message == nullptr || communicator == nullptr)
  {
    return;
  }
  communicator->send(message);
}

#endif
