# Compile all .cpp files
file(GLOB SOURCES "**/*.cpp")

# Create libOpenSpa.a static library
add_library(OpenSpa STATIC ${SOURCES})
