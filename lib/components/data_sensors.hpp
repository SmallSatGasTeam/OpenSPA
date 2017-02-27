#ifndef DATA_SENSORS_HPP
#define DATA_SENSORS_HPP

#include <vector>
#include <string>
#include "drivers/Adafruit_BNO055/Adafruit_BNO055.h"
#include "../component.hpp"

enum Index
{
  BARO,
  TEMP_IN,
  TEMP_EX,
  LIGHT,
  UV,
  GYRO,
  GPS,
  CAMERA
};

class DataSensors : public Component
{
public:
  DataSensors()
  {
    appInit();
  }
  void appInit();
  void sendSpaData(LogicalAddress);
  void handleSpaData(std::shared_ptr<SpaMessage>);
private:
  Adafruit_BNO055 sensor_gyro = Adafruit_BNO055();
  void initGyro();
  std::vector<std::string> dataPackage(8, "x"); 
};

#endif
