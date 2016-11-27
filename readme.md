# Open SPA (Space Plug and Play Architecture)

Open source minimalist implementation of Space Plug and Play Architecture.

SPA is a specification for a modular satellite software architecture. Each
part of satellite functionality is separated into a SPA component. SPA components
all reside in a network, components communicate with each other in a standard
way, and contact each other with their network address as opposed to their physical
address (I.E. I2C address, or some other physical address).

Logic is separated in a layered manner, with each layer operating at a higher level
than those below it. OpenSPA will separate logic into the following layers:

For a basic overview of Space Plug and Play Architecture See:
http://digitalcommons.usu.edu/cgi/viewcontent.cgi?article=1408&context=gradreports

A SPA network is composed of several different subnets, each communicating via
a different protocol. SPA has typically supported communication via I2C, USB,
SpaceWire, and UDP Sockets. At the head of each subnet is a subnet manager. Each
subnet manager is a separate software process. Subnet managers communicate with each
other with UDP sockets through the local subnet manager.

## Getting Started
##### Build Docs
  * Install doxygen
  * Run doxygen Doxyfile

##### Running Tests
  * Install google test
  * run Google Test

<!-- ## Developer Notes
#####  Abstraction Layer
* Abstract platform specific functionality like sockets
##### Testing
##### Documentation -->
  <!-- //! I am the brief message, I give a short overview of what a method does
  //! \param myParam - I describe a parameter
  //! \return - I describe a return value
  bool example(int myParam){return true;} -->
