#ifndef SPA_SUBSCRIPTION_REPLY_HPP
#define SPA_SUBSCRIPTION_REPLY_HPP

#include <cstdint>

#include <spa_message.hpp>

struct SpaSubscriptionReply:public SpaMessage{

	SpaSubscriptionReply(
		uint8_t version,
		uint8_t priority,
		LogicalAddress producerAddress,
		LogicalAddress consumerAddress,
		uint16_t dialogId,
		uint8_t replyType
		):
		SpaMessage(version, priority, 48, producerAddress, consumerAddress, 0, 0x47),
		dialogId(dialogId),
		replyType(replyType){}

		
		uint16_t dialogId;
		uint8_t replyType; // 0 if accepted, 1 if denied, 2 if cancelled
};
#endif
