#ifndef AEROBOOM_HPP
#define AEROBOOM_HPP

#include <iostream>
#include "../component.hpp"
#include "GPIO/GPIOManager.h"
#include "GPIO/GPIOConst.h"

class Aeroboom : public Component
{
public:
  Aeroboom(std::shared_ptr<SpaCommunicator> spaCommunicator, LogicalAddress address)
     : Component(spaCommunicator, address)
  {
    appInit();
  }

  
  ~Aeroboom()
  {
    delete manager;
    manager = nullptr;
  }

  void appInit()
  { // Pin 10 under P8 header
    pin = GPIO::GPIOConst::getInstance()->getGpioByKey("P8_10");
    auto ioSet = manager->setDirection(pin, GPIO::OUTPUT);
    if (!ioSet) std::cout << "GPIO failed" << std::endl;
  }

  void sendSpaData(LogicalAddress);
  void handleSpaData(std::shared_ptr<SpaMessage>);
  void setDestination(LogicalAddress);
private:
  bool shouldDeploy();
  bool deploy();
  bool inRange(double&);
  void sendConfirmation();
  GPIO::GPIOManager* manager = GPIO::GPIOManager::getInstance();
  int pin;
  std::string boomMessage;
  bool deployRequested = false;
  bool deployConfirmed = false;
  const double MIN_DEPLOY = 30.0;
  const double MAX_DEPLOY = 44.0;
};

#endif 
