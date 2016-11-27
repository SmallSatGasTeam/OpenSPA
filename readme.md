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
##### Developer Tools
OpenSPA relies on a handful of developer tools. Here is a list of things that should be set up on your system.
* Git - Version control system
* Google Test - Unit testing framework
* Doxygen - Documentation generator
* Cmake - Build system automation
* Make - Build automation

##### Build Project
###### TLDR
  * Install Cmake
  * Run Cmake in project directory `cmake .`
  * Run generated makefile  `make [optional-target]`

OpenSPA uses Cmake for a build system. Makefiles are generally platform dependent,
so to allow cross platform builds a makefile for each system. Cmake will generate those
make files for us.

There are numerous cmake installation tutorials out there in the wild. It may be worth checking to see if your system package manager has a cmake package before trying to build cmake from source.
* Install Cmake
  * Installing cmake from source - https://cmake.org/install/

##### Build Docs

###### TLDR
  * Install Doxygen
  * Run doxygen with project doxyfile `doxygen ./Doxyfile`
  * View your docs. They should now live in `docs/`

OpenSPA uses the documentation generator Doxygen to build documentation. Annotated source code is parsed by doxygen, and latex, and html files are generated.

 Doxygen can be built from source, or a precompiled binary
can be downloaded from your favorite package manager.
  * To Install from package manager
      * Mac with Homebrew setup
        * `brew install doxygen`
      * Linux from package manager
        * If you are not using ubuntu, mint, or debian, your linux distrobution might not use apt-get. Search for doxygen on your distrobutions package manager
        * `apt-get install doxygen`
      * Windows Chocolatey (package manager) also has a doxygen package that has not been tested by the maintainers, but does exist.
        * With chocolatey installed
        * `choco install doxygen.install`
  * To install from source - If installing from a package manager is not working out.
    * Here is a link to the doxygen project download package
      * http://www.stack.nl/~dimitri/doxygen/download.html
    * Follow directions to download, compile, and install doxygen

  Now doxygen should be available to you on the commandline. You can test this by running `doxygen --version`. This should print out the doxygen version number. If this does not work, you have missed something above.

  Doxygen is a documentation generator that will parse the source code, and build html and latex documentation from the source code. Now that you have doxygen running we need to generate the documentation.

  Doxygen is configured with a file titled `Doxyfile`.

  * Build Documentation
    * Invoke commandline tool
      * `doxygen Doxyfile`

This will read all configuration options from the Doxyfile, find and parse the source code, and generate the documentation.

If the documentation is successfully built, there should be a new directory title `docs/` that should contain both html, and latex documentation.

* Read Docs
  * Open up `docs/html/index.html` in your web browser to browse docs

##### Running Tests
OpenSPA uses Google Test testing framework for unit testing. To run OpenSPA's test suite you will first have to install google test.

Installing GoogleTest can be an arduous process, and one that has already been documented decently well. Instead of giving a step by step example, we link to helpful resources.
  * Install google test
    * For Mac - Here is a link to a tutorial
      * http://ysonggit.github.io/system/2015/01/01/install-gtest-on-mac-os-yosemite.html
    * For Linux - Here is another good resource
      * https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
    * For Windows - Here is a good resource
      * https://blog.jetbrains.com/rscpp/unit-testing-google-test/

OpenSPA uses CMake for build system. To run tests you must first have both Cmake and Google Test installed.

  * To run test suite: 
    * Ensure Cmake is installed
    * Ensure Google Test is installed
    * Generate a makefile with Cmake `cmake .`
    * Build tests with makefile `make runTests`
    * Run test executable `./runTests`

## Developer Notes
#####  Abstraction Layer
OpenSPA is currently being developed for embedded linux systems. In order to keep system portability an option we employ the use of what we call a 'Platform Abstration Layer'. Essentially this means that whenever you would need to rely on a system call, or some system specific functionality (I.E. Linux Socket), you would build a wrapper around that system specific functionality. This limits the platform dependance to a single file, which allows OpenSPA to be usable on a wide variety of platforms.

<!-- * Platform Abstrations live ... TODO document where these live -->
##### Testing
OpenSPA uses google test for unit testing, as well as cmake for a build system. The short version of running tests is:

Classes should be kept small, and have functioning unit tests. When adding a new header file for a class, a header file of the same name should be added to the `test/` directory.
 It will also need to be included in th

To add a new class to the project:
  * Create header file `my_class_name.hpp` (File names should be snake case - lowercase words seperated with underscores)
    * Define class
    ```cpp
    #ifndef MY_CLASS_NAME_HPP
    #define MY_CLASS_NAME_HPP
      class MyClassName{};
    #endif
    ```
      * Must have include guards
      * Class name should be UpperCamelCase, where each first letter of a words is capitalized. Including the first word.  
  * Add new testing file `test/my_class_name.hpp`
  * Write tests for your class
    ```cpp
    #include "../path/to/my_class_name.hpp"

    TEST(MyClassName, myMethod){
      MyClassName myClass;
      EXPECT_EQ(myClass.myMethod(),0);
    }
    ```
      * Be sure to include class header in test file
  * Include your test header in main test file
    * Open `test/gtest_main.cpp`
    * Include your new test header file
  * Hooray! Now you can run your tests! :D


##### Documentation
OpenSPA uses doxygen to build documentation from source code. Essentially this means that you add comments with a special format in the code, and then doxygen can build pretty html docs can be referenced by all other developers and users.

Here is an example of what this might look like to document a function.
```cpp
  //! I am the brief message, I give a short overview of what a method does. I need to be followed by a whitespace

  //! \param myParam - I describe myParameter
  //! \return - I describe a return value
  bool example(int myParam){return true;}
```
