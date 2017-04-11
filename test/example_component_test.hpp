#include <example_component.hpp>

class ExampleComponentTest : public::testing::Test
{
public:
  virtual void SetUp()
  {
      LogicalAddress localAddress(1, 0);
      std::vector<SpaCommunicator::Com> comms = {
              std::make_shared<LocalCommunicator>(sock, routingTable, localAddress)};
      std::shared_ptr<SpaCommunicator> spaCom = std::make_shared<SpaCommunicator>(localAddress, comms);

      ExampleComponent comp(spaCom);
      comp.appInit();
  }

};

TEST_F(ExampleComponentTest, component__send_message)
{

 Example_Component example;
 LogicalAddress address(1, 0);
 uint8_t opcode = 1;
 shared_ptr<SpaMessage> mesg = std::make_shared<SpaMessage>(address, opcode); //possibly replace with a 1 instead of using a variable
 example.sendMsg(mesg);

  EXPECT_TRUE(example.sent);

}
