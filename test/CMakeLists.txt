
find_package(GTest REQUIRED)
# find_package(GMock REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})


add_executable(tests main.cpp)

# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(tests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)

include_directories(../lib)
target_link_libraries(tests OpenSpa)
