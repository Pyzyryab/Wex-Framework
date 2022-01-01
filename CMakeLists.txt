cmake_minimum_required(VERSION 3.8)

set(This Wex) # Create a variable to reference the project's name

project(${This} CXX) # The name of the project and the languages used in

set(CMAKE_CXX_STANDARD 20) # This project will be completly build only using C++ 20
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# add_subdirectory(src)
set(Headers
    ./include/Wex/Wex.hpp
)
set(Sources
    src/Wex.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})

enable_testing() # Telling CMake that we will have unit tests
add_subdirectory(test) # Project tests