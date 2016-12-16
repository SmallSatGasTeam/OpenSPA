
file(GLOB SOURCES "*.cpp")
# add_executable(runTests ${SOURCES})

add_library(OpenSpa STATIC ${SOURCES})
# set_target_properties(part4library PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
# set_target_properties(part4library PROPERTIES OUTPUT_NAME part4library${BUILD_POSTFIX})
