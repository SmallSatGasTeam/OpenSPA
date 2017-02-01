#include "component.hpp"

void Component::sendMsg(std::shared_ptr<SpaMessage> message)
{
  if (message == nullptr) return;
  else sent = true;
}
