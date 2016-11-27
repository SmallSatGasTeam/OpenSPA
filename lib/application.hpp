#ifndef APPLICATION_HPP
#define APPLICATION_HPP
class Application{
  virtual void appInit();
  virtual void appShutdown();
  virtual int32_t publish();
  virtual void registerRequest();
  virtual void sendMsg();
  virtual void receiveMessage(SpaMessage);
};
#endif
