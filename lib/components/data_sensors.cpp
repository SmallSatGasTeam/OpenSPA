#include "data_sensors.hpp"
#include "../messages/spa_data.hpp"
#include <iostream>
#include <fstream>

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

double readUV()
{
	double datum;
	unsigned int voltage;
	std::ifstream file;

	file.open("/sys/bus/iio/devices/iio:device0/in_voltage0_raw");
	file >> voltage;
	file.close();

	datum = 5 / 1023.0 * voltage * 10;

	return datum;
}
