#ifndef AEROBOOM_HPP
#define AEROBOOM_HPP

#include "../component.hpp"
#include "../messages/op_codes.hpp"
#include "addresses.hpp"
#include <iostream>
#include "GPIO/GPIOManager.hpp"
#include "GPIO/GPIOConst.hpp"

class Aeroboom : public Component
{
public:
  Aeroboom(std::shared_ptr<SpaCommunicator> spaCommunicator, LogicalAddress address)
      : Component(spaCommunicator, address)
  {
        appInit();
  }

   virtual ~Aeroboom()
   {
    delete manager;
    manager = nullptr;
   }

  void appInit() 
  { // Pin 10 under P8 header
    manager = GPIO::GPIOManager::getInstance();
    pin = GPIO::GPIOConst::getInstance()->getGpioByKey("P8_10");
    auto ioSet = manager->setDirection(pin, GPIO::OUTPUT);
    if (!ioSet) std::cout << "GPIO failed" << std::endl;
  }

  void sendSpaData(LogicalAddress destination)
  {
    auto msg = std::make_shared<SpaData<std::string>>(
        0,       // version
        0,       // priority
        address, // source
        destination,
        dialogId,
        0, // sequeceIndex
        0, // sequenceCount
        0, // xTEDS interface ID
        0, // xTEDS messageID
        boomMessage);

    sendMsg(msg);
  }

  void handleSpaData(std::shared_ptr<SpaMessage> message)
  {
    if (message == nullptr)
    {
      std::cout << "Invalid SpaData!!" << std::endl;
    }
    else if (message->spaHeader.source == ADDRESS_FILTER)
    {
      deployIfInRange(message);
    }

    else
    {
      delegateMessage(message);
    }
  }

  bool wasConfirmed() { return deployConfirmed; }

  //  void setDestination(LogicalAddress);
private:
  bool shouldDeploy();
  bool deploy();

  void delegateMessage(std::shared_ptr<SpaMessage>);

  void deployIfInRange(std::shared_ptr<SpaMessage>);

  void sendConfirmation();
  GPIO::GPIOManager* manager;
  int pin;
  std::string boomMessage;
  bool deployRequested = false;
  bool deployConfirmed = false;
  const double MIN_DEPLOY = 30.0;
  const double MAX_DEPLOY = 44.0;
  
};
#endif 
