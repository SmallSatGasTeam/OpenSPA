#include "data_sensors.hpp"
#include "../messages/spa_data.hpp"
#include <iostream>

void DataSensors::sendSpaData(LogicalAddress destination)
{
  auto msg = std::make_shared<SpaData<std::vector<std::string>>>(
      0,       // version
      0,       // priority
      address, // source
      destination,
      dialogId,
      0, // sequeceIndex
      0, // sequenceCount
      0, // xTEDS interface ID
      0, // xTEDS messageID
      dataPackage);

  sendMsg(msg);

  communicator->send(msg);
  dataPackage = std::vector<std::string>(8, "x");
}

void DataSensors::handleSpaData(std::shared_ptr<SpaMessage> msg)
{
  // if (message->payload == "takephoto") takePhoto();
  msg = nullptr;
  return;
}
