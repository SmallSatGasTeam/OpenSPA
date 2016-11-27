set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 2.6)
project(OpenSPA)

##
# Locate GTest
##
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
set(SOURCES test/gtest_main.cpp src/spa_communicator.cpp)
#file(GLOB SOURCES "src/*.hpp" "src/*.cpp" )
add_executable(runTests ${SOURCES})
#add_executable(runTests test/gtest_main.cpp)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
