cmake_minimum_required(VERSION 3.10)

# Project name and version
project(DFSServer VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
)

# Add the executable target
add_executable(DFSServer ${SOURCES})

# Link libraries
if(WIN32)
    target_link_libraries(DFSServer ws2_32)  # For Windows networking
endif()

# Optionally define build types
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)

# Enable debugging symbols in Debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug build: Enabling debug symbols.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release build: Enabling optimizations.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()
