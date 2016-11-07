# Open SPA (Space Plug and Play Architecture)

Open source minimalist implementation of Space Plug and Play Architecture.

SPA is a specification for a modular satellite software architecture. Each
part of satellite functionality is separated into a SPA component. SPA components
all reside in a network, components communicate with each other in a standard
way, and contact each other with their network address as opposed to their physical
address (I.E. I2C address, or some other physical address).

Logic is separated in a layered manner, with each layer operating at a higher level
than those below it. OpenSPA will separate logic into the following layers:

* SPA Component (Performs a specific action. I.E. Collects data with a sensor)
* SPA API   
  * SPA Message Layer (Handles serializing and deserializing SPA messages)
* SPA Middleware
  * SPA Data Layer ( Adds support for asynchronous message transmission )
  * SPA Network Layer (Handles routing and transmission of data between nodes in SPA network)
* Platform Abstraction Layer (Abstracts platform specific APIs I.E. Threading, Sockets)

For a basic overview of Space Plug and Play Architecture See:
http://digitalcommons.usu.edu/cgi/viewcontent.cgi?article=1408&context=gradreports

To run tests `platformio run test`
To build native program `platformio run`
