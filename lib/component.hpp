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
    address(address) {}
  // virtual ~Component(){}
  virtual void appInit() = 0;
  // virtual void appShutdown();
  // virtual int32_t publish();
  // virtual void registerRequest();

  template <typename T>
  virtual void sendMsg(T message);
  virtual void subscribe(LogicalAddress);
  // virtual void receiveMessage(SpaMessage);
protected:
  LogicalAddress address;
  Com communicator;
private:
  uint16_t dialogId;
};
#endif
