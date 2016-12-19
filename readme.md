# OpenSPA

OpenSPA is an open-source **Space Plug and Play Architecture (SPA)** services manager for Linux-based (and, eventually, non-Linux) spacecraft systems. OpenSPA allows for a more standardized and streamlined method of handling systems with many connected components. Developed with undergraduate CubeSat teams using systems such as Beaglebone Blacks, Arduinos, and Raspberry Pis in mind, OpenSPA's purpose is to make missions less costly, require less development time, and have higher success rates.

SPA itself is a specification for a kind of modular satellite software architecture. It is a set of standardized protocols based on the Open Systems Interconnection networking model. 

For a brief introduction on the inner workings of OpenSPA, see [this writeup.](https://drive.google.com/file/d/0ByiGNyJUAlpISUo5WDFwSkh3YU0/view?usp=sharing)

For a very detailed look into the machinations of SPA in general, see [Jacob Holt Christensen's dissertation.](http://digitalcommons.usu.edu/etd/1422/)

## Project Status
  * Version Alpha 0.0.1
    * Planning API's and project planning

## Getting Started
### Developer Tools
OpenSPA relies on a handful of developer tools. Here is a list of things that should be set up on your system.
* Git - Version control system
* Google Test - Unit testing framework
* Doxygen - Documentation generator
* CMake - Build system automation
* Make - Build automation

<!-- ## How to Contribute  -->
<!-- TODO -->
### Build Project
#### TLDR
  * Install CMake
  * Run CMake in project directory `cmake .`
  * Run generated makefile  `make [optional-target]`

OpenSPA uses CMake for a build system. Makefiles are generally platform-dependent, so CMake generates a different Makefile for each system in order to allow for cross-plaform functionality.

There are numerous CMake installation tutorials out there in the wild. It may be worth checking to see if your system package manager has a CMake package before trying to build cmake from source (e.g., `apt-get install cmake` ).

* Install CMake
  * Installing CMake from source - https://cmake.org/install/

### Build Docs

#### TLDR
  * Install Doxygen
  * Run Soxygen with project doxyfile `doxygen ./Doxyfile`
  * View your docs. They should now live in `docs/`

OpenSPA uses the documentation generator Doxygen to build documentation. Annotated source code is parsed by Doxygen to generate LaTeX and HTML files.

 Doxygen can be built from source, or a precompiled binary
can be downloaded from your favorite package manager.
  * To install from package manager
      * Mac with Homebrew setup
        * `brew install doxygen`
      * Linux from package manager
        * If you are not using Ubuntu, Mint, or Debian, your Linux distribution might not use apt-get. Search for doxygen on your distribution's package manager
        * `apt-get install doxygen`
      * Windows Chocolatey (package manager) also has a Doxygen package that has not been tested by the maintainers, but does exist.
        * With chocolatey installed
        * `choco install doxygen.install`
  * To install from source - If installing from a package manager is not working out.
    * Here is a link to the Doxygen project download package
      * http://www.stack.nl/~dimitri/doxygen/download.html
    * Follow directions to download, compile, and install Doxygen

  Now Doxygen should be available to you on the command line. You can test this by running `doxygen --version`. This should print out the doxygen version number. If this does not work, you have missed something above.

  Doxygen is configured with a file titled `Doxyfile`.

  * Build Documentation
    * Invoke commandline tool
      * `doxygen Doxyfile`

This will read all configuration options from the Doxyfile, find and parse the source code, and generate the documentation.

If the documentation is successfully built, there should be a new directory title `docs/` that should contain both HTML and LaTeX documentation.

* Read Docs
  * Open up `docs/html/index.html` in your web browser to browse docs

### Running Tests
OpenSPA uses Google Test testing framework for unit testing. To run OpenSPA's test suite you will first have to install Google Test.

Installing Google Test can be an arduous process, and one that has already been documented decently well. Instead of giving a step by step example, we will link to helpful resources.
  * Install google test
    * Mac - Here is a link to a tutorial
      * http://ysonggit.github.io/system/2015/01/01/install-gtest-on-mac-os-yosemite.html
    * For Linux - Here is another good resource
      * https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
    * For Windows - Here is a good resource
      * https://blog.jetbrains.com/rscpp/unit-testing-google-test/

OpenSPA uses CMake for build system. To run tests you must first have both Cmake and Google Test installed.

  * To run test suite:
    * Ensure Cmake is installed
    * Ensure Google Test is installed
    * Generate a makefile with CMake `cmake .`
    * Build tests with makefile `make runTests`
    * Run test executable `./runTests`

## Developer Notes
###  Abstraction Layer
OpenSPA is currently being developed for embedded Linux systems. In order to keep system portability an option, we employ the use of what we call a "Platform Abstration Layer." Essentially this means that whenever we need to rely on a system call or some system-specific functionality (e.g, a Linux socket), we build a wrapper around that system-specific functionality. This limits the platform dependance to a single file, which allows OpenSPA to be usable on a wide variety of platforms.

<!-- * Platform Abstrations live ... TODO document where these live -->
### Testing
OpenSPA uses Google Test for unit testing and CMake for a build system. The short version of running tests is this:

Classes should be kept small, and have functioning unit tests. When adding a new header file for a class, a header file of the same name should be added to the `test/` directory.
 It will also need to be included in th <!-- TODO finish this sentence lol -->

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


### Documentation
OpenSPA uses Doxygen to build documentation from source code. This means that one can add comments with a special format in the code so that Doxygen may build pretty HTML docs that can be referenced by all other developers and users.

Here is an example of what this might look like to document a function.
```cpp
  //! I am the brief message, I give a short overview of what a method does. I need to be followed by a whitespace

  //! \param myParam - I describe myParameter
  //! \return - I describe a return value
  bool example(int myParam){return true;}
```
