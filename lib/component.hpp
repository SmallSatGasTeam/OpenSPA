#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "spa_communicator.hpp"
#include <memory>

class Component
{
public:
  typedef std::shared_ptr<SpaCommunicator> Com;

  Component(Com communicator = nullptr) : communicator(communicator) {}
  // virtual ~Component(){}
  virtual void appInit() = 0;
  // virtual void appShutdown();
  // virtual int32_t publish();
  // virtual void registerRequest();
  virtual void sendMsg(std::shared_ptr<SpaMessage> message);
  // virtual void receiveMessage(SpaMessage);
protected:
  // LogicalAddress address;
  Com communicator;
};
#endif
