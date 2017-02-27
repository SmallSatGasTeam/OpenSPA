#include <iostream>
#include "drivers/Adafruit_BNO055/Adafruit_BNO055.h"
#include "data_sensors.hpp"

void DataSensors::initGyro()
{
  while (!sensor_gyro.begin())
  {
    std::cerr << "Couldn't detect BNO055 gyroscope!" << std::endl;
  }
  sensor_gyro.setExtCrystalUse(true);  
}

void DataSensors::appInit()
{
  initGyro();
}

void DataSensors::sendSpaData(LogicalAddress destination)
{
  return;
}

void DataSensors::handleSpaData(std::shared_ptr<SpaMessage>);
{
  return;
}
