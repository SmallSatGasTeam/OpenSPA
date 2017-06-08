#include <string>
#include <fstream>
#include "../component.hpp"
#include "../messages/op_codes.hpp"

class Radio : public Component
{
public:
  Radio(std::shared_ptr<SpaCommunicator> spaCommunicator, LogicalAddress address)
      : Component(spaCommunicator, address)
  {
        appInit();
  }

   virtual ~Radio()
   {
   }

  void appInit() 
  { 
  }

  void sendSpaData(LogicalAddress destination)
  {
		//Listen with sockets or whatever, get a message, and send it up as radioMessage
		std::string radioMessage;
		std::string sendMessage;
		std::ifstream radiofd("/dev/ttyO4");
		radiofd >> radioMessage;

		if      (radioMessage == "c" || radioMessage == "C") sendMessage = "takePhoto";
		else if (radioMessage == "b" || radioMessage == "B") sendMessage = "deploy";
		else if (radioMessage == "y" || radioMessage == "Y") sendMessage = "confirm";
		else if (radioMessage == "n" || radioMessage == "N") sendMessage = "cancel";
    auto msg = std::make_shared<SpaData<std::string>>(
        0,       // version
        0,       // priority
        address, // source
        destination,
        dialogId,
        0, // sequeceIndex
        0, // sequenceCount
        0, // xTEDS interface ID
        0, // xTEDS messageID
        sendMessage);

    sendMsg(msg);
  }

  void handleSpaData(std::shared_ptr<SpaMessage> message)
  {
		auto castMessage = std::dynamic_pointer_cast<SpaData<std::string>>(message);
    if (message == nullptr)
    {
      std::cout << "Invalid SpaData!!" << std::endl;
    }

		std::ofstream radiofd;
		radiofd.open("/dev/ttyO4");
		if(!radiofd.is_open())
		{
			 std::cout << "Radio failed to open" << std::endl;
			 return;
		}
		

		radiofd << castMessage->payload;
		radiofd.close();

		return;
  }


};
