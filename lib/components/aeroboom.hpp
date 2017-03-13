#ifndef AEROBOOM_HPP
#define AEROBOOM_HPP

#include <iostream>
#include "../component.hpp"
#include "GPIO/GPIOManager.h"
#include "GPIO/GPIOConst.h"

class Aeroboom : public Component
{
public:
  Aeroboom()
  {
    appInit();
  }
  
  ~Aeroboom()
  {
    delete manager;
    manager = nullptr;
  }

  void appInit()
  {
    pin = GPIO::GPIOConst::getInstance()->getGpioByKey("P8_10"); // Pin 10 under P8 header
    auto ioSet = manager->setDirection(pin, GPIO::OUTPUT);
    if (!ioSet) std::cout << "GPIO failed" << std::endl;
  }

  void sendSpaData(LogicalAddress);
  void handleSpaData(std::shared_ptr<SpaMessage>);
private:
  bool deploy();
  GPIO::GPIOManager* manager = GPIO::GPIOManager::getInstance();
  int pin;
};

#endif 
