cmake_minimum_required(
    VERSION 3.8
)

set(This WexTests)

project(${This}) # The name of the project and the languages used in

set(CMAKE_CXX_STANDARD 20) # This project will be completly build only using C++ 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_COMPILER clang++)

add_compile_options(-stdlib=libc++)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/main.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(
  GLOB_RECURSE
    Sources
        ./Examples/**.cpp
        ./Wex/**.cpp
    )

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    Wex
)


add_module(mod ${PROJECT_SOURCE_DIR}/include/Wex/**.ixx)


add_test(
    NAME ${This}
    COMMAND Wex
)

add_compile_options(
    -DGTEST_HAS_PTHREAD=1
)