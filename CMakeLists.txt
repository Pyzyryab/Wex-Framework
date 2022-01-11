cmake_minimum_required(VERSION 3.8)

set(This Wex) # Create a variable to reference the project's name

project(${This} CXX) # The name of the project and the languages used in

set(CMAKE_CXX_STANDARD 20) # This project will be completly build only using C++ 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PREBUILT_MODULE_DIR ${CMAKE_BINARY_DIR}/modules)
set(STD_MODULES_DIR "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.30.30705\\ifc\\x64\\Debug")

function(add_module name)
    file(MAKE_DIRECTORY ${PREBUILT_MODULE_DIR})
    add_custom_target(${name}.ifc
      COMMAND
        ${CMAKE_CXX_COMPILER}
        /std:c++latest
        # /experimental:module
        /c
        /EHsc
        /MDd
        # /stdIfcDir ${STD_MODULES_DIR}
        # /ifcSearchDir ${STD_MODULES_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
        /module:export
        /ifcOutput
        ${PREBUILT_MODULE_DIR}/${name}.ifc
        /Fo${PREBUILT_MODULE_DIR}/${name}.obj
      )
endfunction()


file(
  GLOB_RECURSE
    Headers
      ./include/Wex/**.ixx
    Sources
      src/Wex/**.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})

set(CUSTOM_MODULES_DIR include)
add_module(my_module ${CUSTOM_MODULES_DIR}/Wex/**.ixx)


# MSVC Compiler options and flags
target_compile_options(${This}
  BEFORE
  PUBLIC
  /std:c++latest
  # /experimental:module
  # /ifcSearchDir ${STD_MODULES_DIR}
  /reference my_module=${PREBUILT_MODULE_DIR}/my_module.ifc 
  /EHsc
  /MDd
)
target_link_libraries(${This} 
  ${PREBUILT_MODULE_DIR}/my_module.obj
)
add_dependencies(${This} my_module.ifc)

enable_testing() # Telling CMake that we will have unit tests
add_subdirectory(test) # Project tests