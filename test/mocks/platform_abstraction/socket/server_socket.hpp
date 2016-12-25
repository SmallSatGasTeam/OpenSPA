#include <platform_abstraction/socket/server_socket.hpp>
class MockServerSocket : public ServerSocket {
 public:
  //  virtual bool send(std::string address, uint16_t port, std::string message){
   MOCK_METHOD4(send, bool(std::string, uint16_t, uint8_t*, uint32_t));

//   // MOCK_METHOD0(PenUp, void());
//   // MOCK_METHOD0(PenDown, void());
//   // MOCK_METHOD1(Forward, void(int distance));
//   // MOCK_METHOD1(Turn, void(int degrees));
//   // MOCK_METHOD2(GoTo, void(int x, int y));
//   // MOCK_CONST_METHOD0(GetX, int());
//   // MOCK_CONST_METHOD0(GetY, int());
};

// class Test{
// public:
//   virtual bool test(int a){return true;}
//   int a;
// };
//
// class SuperTest:public Test{};
//
// class TestMock:public SuperTest{
// public:
//   MOCK_METHOD1(test, bool(int));
// };
