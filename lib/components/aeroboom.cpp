#include "aeroboom.hpp"
#include <unistd.h>
#include <iostream>

void Aeroboom::sendSpaData(LogicalAddress address)
{
  return;
}

void Aeroboom::handleSpaData(std::shared_ptr<SpaMessage> message)
{
  return;
}

bool Aeroboom::deploy()
{
  // TODO Have it send the cout messages to the logging component

  std::cout << "ATTEMPTING BOOM DEPLOY..." << std::endl;
  manager->setValue(pin, GPIO::HIGH);
  auto slept = sleep(3);
  manager->setValue(pin, GPIO::LOW);
  std::cout << "DONE" << std::endl;

  return slept;
}
