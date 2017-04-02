#include "aeroboom.hpp"

void Aeroboom::deployIfInRange(std::shared_ptr<SpaMessage> message)
{
  auto castMessage = std::dynamic_pointer_cast<SpaData<double>>(message);

  auto val = castMessage->payload;
  if (val > MIN_DEPLOY && val < MAX_DEPLOY)
    deploy();
}


void Aeroboom::delegateMessage(std::shared_ptr<SpaMessage> message)
{
  auto castMessage = std::dynamic_pointer_cast<SpaData<std::string>>(message);

  if (castMessage->payload == "deploy" && !deployConfirmed)
  {
    deployRequested = true;
    sendConfirmation();
  }
  else if (castMessage->payload == "confirm" && deployRequested)
  {
    deployConfirmed = true;
    deploy();
  }
  else if (castMessage->payload == "cancel" && deployRequested)
  {
    deployRequested = false;
  }
  else
  {
    std::cout << "Unrecognized message" << std::endl;
  }
}

void Aeroboom::sendConfirmation()
{
  boomMessage = "DEPLOYMENT COMMAND DETECTED. PRESS 'y' TO CONFIRM OR 'n' TO CANCEL.";
  sendSpaData(ADDRESS_LOGGING);
}

bool Aeroboom::deploy()
{
  boomMessage = "======= ATTEMPTING BOOM DEPLOY... =======";
  sendSpaData(ADDRESS_LOGGING);

//  manager->setValue(pin, GPIO::HIGH);
  auto slept = sleep(3);
//  manager->setValue(pin, GPIO::LOW);

  boomMessage = "=======           DONE            =======";
  sendSpaData(ADDRESS_LOGGING);


  return slept;
}


