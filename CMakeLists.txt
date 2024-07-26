cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MyProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(my_program
    src/main.cpp
    src/MyClass.cpp
)

# Include header files
target_include_directories(my_program PUBLIC include)
