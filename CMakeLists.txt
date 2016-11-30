set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 2.6)
project(OpenSPA)

# find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)
# include_directories(include)
# include_directories(${GTEST_INCLUDE_DIRS})
# include_directories(${GMOCK_INCLUDE_DIRS})


# file(GLOB SOURCES "src/*.cpp" test/main.cpp)
# add_executable(runTests ${SOURCES})

# Link runTests with what we want to test and the GTest and pthread library
# target_link_libraries(runTests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)
add_subdirectory(test)
add_subdirectory(lib)
include_directories(lib)
