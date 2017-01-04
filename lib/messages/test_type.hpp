#include <spa_message.hpp>

struct TestDerivedMessage : public SpaMessage{
public:
  TestDerivedMessage(LogicalAddress la, uint8_t opcode)
    :SpaMessage(la, opcode, SpaMessage::TEST_TYPE){}

  TestDerivedMessage(){}
};
