cmake_minimum_required(VERSION 3.8)

set(This Wex) # Create a variable to reference the project's name

project(${This} CXX) # The name of the project and the languages used in


set(CMAKE_CXX_STANDARD 20) # This project will be completly build only using C++ 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PREBUILT_MODULE_DIR ${CMAKE_BINARY_DIR}/modules)
set(CMAKE_CXX_COMPILER clang++)
file(
  GLOB_RECURSE
    Headers
      ./include/Wex/**.ixx
    Sources
      src/Wex/**.cpp
)
if (MSVC)
  set(STD_MODULES_DIR "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.30.30705\\ifc\\x64\\Debug")
  function(add_module name)
  file(MAKE_DIRECTORY ${PREBUILT_MODULE_DIR})
  add_custom_target(${name}.ifc
    COMMAND
      msbuild
      /std:c++latest
      /experimental:module
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

  add_library(${This} STATIC ${Headers} ${Sources})

  set(CUSTOM_MODULES_DIR include)
  add_module(my_module ${CUSTOM_MODULES_DIR}/Wex/**.ixx)


  # MSVC Compiler options and flags
  target_compile_options(${This}
  BEFORE
  PUBLIC
  /std:c++latest
  /experimental:module
  # /ifcSearchDir ${STD_MODULES_DIR}
  /reference my_module=${PREBUILT_MODULE_DIR}/my_module.ifc 
  /EHsc
  /MDd
  )
  target_link_libraries(${This} 
  ${PREBUILT_MODULE_DIR}/my_module.obj
  )
  add_dependencies(${This} my_module.ifc)

  # Testing with the googletest framework it's only working with the 
  # MSVC and the G++ compiler, so until a solution will be found to compile the
  # project with `clang`, the tests options will remain inside this if branch
  enable_testing() # Telling CMake that we will have unit tests
  add_subdirectory(test) # Project tests

else()
  function(add_module name)
    file(MAKE_DIRECTORY ${PREBUILT_MODULE_DIR})
    add_custom_target(${name}.pcm
        COMMAND
          ${CMAKE_CXX_COMPILER}
            -std=c++20
            -stdlib=libstdc++
            -fmodules-ts
            -c
            ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
            -Xclang 
            -emit-module-interface
            -o ${PREBUILT_MODULE_DIR}/${name}.pcm
        )
    endfunction()

    add_compile_options(-v)
    add_compile_options(-fmodules)
    add_compile_options(-fmodules-ts)
    # add_compile_options(-stdlib=libstdc++)
    add_compile_options(-fbuiltin-module-map)
    add_compile_options(-fimplicit-module-maps)
    add_compile_options(-fprebuilt-module-path=${PREBUILT_MODULE_DIR})

    add_module(WexModules src/Wex/**.cpp)
    add_library(Wex STATIC ${Headers} ${Sources})

    add_dependencies(
        Wex WexModules.pcm
    )

endif()
