// class Test{
// public:
//   // Test(){}
//   Test(int a){
//     b = a;
//   }
//   virtual bool test(int a){return true;}
//   int b;
// };
//
// class TestMock:public Test{
// public:
//   TestMock():Test(0){}
//   MOCK_METHOD1(test, bool(int));
// };

#include <local_communicator.hpp>

class MockLocalCommunicator: public LocalCommunicator{
public:
  MockLocalCommunicator(LogicalAddress la):
    LocalCommunicator(nullptr, nullptr, la){}

  MOCK_METHOD1(send, bool(std::shared_ptr<SpaMessage>));
};
