#ifndef SPA_COMMUNICATOR_HPP
#define SPA_COMMUNICATOR_HPP

#include <memory>
#include <vector>


#include "spa_message.hpp"
#include "physical_communicator.hpp"
#include "routing_table.hpp"

class SpaCommunicator {
public:
  typedef std::shared_ptr <PhysicalCommunicator> Com;

  //! Construct SpaCommunicator with only the address of the owning subnet manager

  //! \param currentAddress - logical address of the subnet manager who owns SpaCommunicator
  SpaCommunicator(LogicalAddress currentAddress);

  //! Construct SpaCommunicator, and set a physical communicator

  //! \param currentAddress - logical address of the subnet manager who owns SpaCommunicator
  //! \param communicator - physical communicator that should belong to SpaCommunicator
  SpaCommunicator(LogicalAddress currentAddress, PhysicalCommunicator const & communicator);

  //TODO document
  SpaCommunicator(LogicalAddress currentAddress, std::vector<Com> comms);

  //TODO document
  void addCommunicators(std::vector<Com> comms);

  //! Sends a spa message over the network

  //! \param message - Specialization of a Message to be sent over the network.
  //! \return true if message is successfully sent, false otherwise.
  bool send(SpaMessage message);

template <typename Func>
  void listen(Func messageHandler);


protected:
  //! Method called when something unexpected occurs.
  void handleFailure();

  //! Selects the appropriate physical communicator from list of physical communicators
  //! to send message.

  //! \param address - logical address where message is going to be sent
  //! \param communicators - vector of communicators to be selected from
  Com selectCommunicator(LogicalAddress address, std::vector<Com> const & communicators);

  LogicalAddress currentAddress;
  std::vector<Com> communicators;
};

#endif
