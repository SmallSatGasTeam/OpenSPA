#ifndef RADIO_TEST_HPP
#define RADIO_TEST_HPP

#include "mocks/spa_communicator.hpp"
#include <component.hpp>
#include <messages/spa_data.hpp>
#include <components/radio.hpp>
#include <string>

class RadioTest : public ::testing::Test
{
	public:
		virtual void SetUp()
		{
			spaCom = std::make_shared<MockSpaCommunicator>();
			addr = std::make_shared<LogicalAddress>(0, 0);
		}
		std::shared_ptr<MockSpaCommunicator> spaCom;
		std::shared_ptr<LogicalAddress> addr;


};



TEST_F(RadioTest, basic_tests)
{

	LogicalAddress destination(0,1);
	std::shared_ptr<Radio> radio;
	radio =  std::make_shared<Radio>(spaCom, *addr);

  std::string payload = "Sensor Data Here";

  auto msg = std::make_shared<SpaData<std::string>>(
      0,     // version
      0,     // priority
      *addr, // source
      destination,
      0,
      0, // sequeceIndex
      0, // sequenceCount
      0, // xTEDS interface ID
      0, // xTEDS messageID
      payload);

	radio->handleSpaData(msg);
	EXPECT_TRUE(true);


}
#endif
