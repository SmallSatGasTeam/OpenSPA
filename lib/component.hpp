#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "application_communicator.hpp"
#include <memory>

class Component{
public:
  typedef std::shared_ptr<ApplicationCommunicator> Com;

  Component(Com communicator = nullptr):communicator(communicator){}
  virtual void appInit();
  // virtual void appShutdown();
  // virtual int32_t publish();
  // virtual void registerRequest();
  virtual void sendMsg(std::shared_ptr<SpaMessage> message);
  // virtual void receiveMessage(SpaMessage);
protected:
  LogicalAddress address;
  Com communicator;
};
#endif
