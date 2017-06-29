#include "local_spa_message.hpp"
#include <cstdint>

std::shared_ptr<LocalSpaMessage> LocalSpaMessage::unmarshal1(uint8_t *serialized, uint32_t size)
{
	return std::shared_ptr<LocalSpaMessage>(reinterpret_cast<LocalSpaMessage *>(serialized));

}
