cmake_minimum_required(VERSION 3.10)

# Project name and version
project(DFSServer VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(DFSServer
    src/main.cpp
    src/MyClass.cpp
    src/infrastructures/network/ServerSocketHandler.cpp
)

# Include header files
target_include_directories(DFSServer PUBLIC include)

target_link_libraries(DFSServer ws2_32)