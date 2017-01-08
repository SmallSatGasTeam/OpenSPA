#include <spa_message.hpp>

struct TestDerivedMessage : public SpaMessage
{
public:
  TestDerivedMessage(LogicalAddress la)
      : SpaMessage(la, SpaMessage::TEST_TYPE) {}

  TestDerivedMessage() {}
};
