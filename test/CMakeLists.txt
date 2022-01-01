cmake_minimum_required(
    VERSION 3.8
)

set(This WexTests)

set(Sources
    ./InitialWexTests.cpp
    ./FixtureWexTestExample.cpp
)

add_executable(${This} ${Sources})

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

target_link_libraries(${This} PUBLIC
    gtest_main
    Wex
)

add_test(
    NAME ${This}
    COMMAND ${This}
)