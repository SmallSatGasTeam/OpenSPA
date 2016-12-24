cmake_minimum_required(VERSION 3.0)
project(OpenSPA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "./cmake;${CMAKE_MODULE_PATH}")


find_package(GTest REQUIRED)
# find_package(GMock REQUIRED) TODO I can't figure out how to make this work right

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
# target_link_libraries(runTests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)
add_subdirectory(test)
add_subdirectory(lib)
include_directories(lib)
