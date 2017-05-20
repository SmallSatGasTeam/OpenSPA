#ifndef DATA_SENSORS_HPP
#define DATA_SENSORS_HPP

#include <vector>
#include <string>
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


/*
 * The idea for this class to support asynchronus messaging is to have data-grabbing functions
 * for each sensor that operate concurrently. They'll simply update a spot in the vector that'll
 * then be packaged and sent out with each publication.
 */

class DataSensors : public Component
{
public:
  DataSensors(std::shared_ptr<SpaCommunicator> spaCom, LogicalAddress address)
  : Component(spaCom, address), dataPackage(8, "x")
  {
    appInit();
  }

  virtual ~DataSensors() {}
  void appInit() {}
  void sendSpaData(LogicalAddress);
  void handleSpaData(std::shared_ptr<SpaMessage>);
  void setDataPackage(std::vector<std::string> pkg) { dataPackage = pkg; }
  std::vector<std::string> getDataPackage() { return dataPackage; }
private:
  std::vector<std::string> dataPackage; 
	double readUV();
};

#endif
