#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "messages/spa_subscription_reply.hpp"
#include "messages/spa_subscription_request.hpp"
#include "spa_communicator.hpp"
#include "spa_message.hpp"
#include <iostream>
#include <memory>

class Component
{
public:
  typedef std::shared_ptr<SpaCommunicator> Com;

  Component(Com communicator = nullptr, LogicalAddress address = LogicalAddress(0, 0)) : communicator(communicator),
                                                                                         address(address),
                                                                                         dialogId(0) {}
  virtual ~Component() {}
  virtual void appInit() = 0;
  // virtual void appShutdown();
  // virtual int32_t publish();

  template <typename M>
  void sendMsg(M);

  virtual void receiveMessage(std::shared_ptr<SpaMessage>);

  virtual void handleSubscriptionReply(std::shared_ptr<SpaMessage>);
  virtual void registerSubscriptionRequest(std::shared_ptr<SpaMessage>);
  virtual void subscribe(
      LogicalAddress producer,
      uint8_t priority,
      uint32_t leasePeriod,
      uint16_t deliveryRateDivisor);

protected:
  LogicalAddress address;
  Com communicator;

private:
  uint16_t dialogId;
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
