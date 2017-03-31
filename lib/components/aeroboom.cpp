#include "aeroboom.hpp"
#include "addresses.hpp"
#include <unistd.h>
#include <iostream>

void Aeroboom::sendSpaData(LogicalAddress destination)
{
  auto msg = std::make_shared<SpaData>(
    0, // version
    0, // priority
    address, // source
    destination,
    dialogId,
    0, // sequeceIndex
    0, // sequenceCount
    0, // xTEDS interface ID
    0, // xTEDS messageID
    boomMessage
  );

  sendMsg(msg);
}

void Aeroboom::sendConfirmation()
{
  boomMessage = "DEPLOYMENT COMMAND DETECTED. PRESS 'y' TO CONFIRM OR 'n' TO CANCEL.";
  sendSpaData(ADDRESS_LOGGING);
}

bool Aeroboom::inRange(double & val)
{
  return (val > MIN_DEPLOY && val < MAX_DEPLOY)
}

void Aeroboom::handleSpaData(std::shared_ptr<SpaMessage> message)
{
  if (message->source == ADDRESS_FILTER )
  {
    if (inRange(message->payload)) deploy();
  }
  else if (message->payload == "deploy" && !deployConfirmed)
  {
    deployRequested = true;
    sendConfirmation();
  }
  else if (message->payload == "confirm" && deployRequested)
  {
    deployConfirmed = true;
    deploy();
  }
  else if (message->payload == "cancel" && deployRequested)
  {
    deployRequested = false; 
  }
  else
  {
    std::cout << "Unrecognized message" << std::endl;
  }
}

bool Aeroboom::deploy()
{
  boomMessage = "======= ATTEMPTING BOOM DEPLOY... ======="
  sendSpaData(ADDRESS_LOGGING);

  manager->setValue(pin, GPIO::HIGH);
  auto slept = sleep(3);
  manager->setValue(pin, GPIO::LOW);

  boomMessage = "=======           DONE            ======="
  sendSpaData(ADDRESS_LOGGING);


  return slept;
}
