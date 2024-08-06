cmake_minimum_required(VERSION 3.10)

# Project name and version
project(DFSNode VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(DFSNode
    src/main.cpp
    src/MyClass.cpp
    src/SocketHandler.cpp
)

# Include header files
target_include_directories(DFSNode PUBLIC include)

target_link_libraries(DFSNode ws2_32)