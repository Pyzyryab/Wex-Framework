/**
 * @file WexTest.cpp
 * @author Alex Vergara (pyzyryab@utanota.com)
 * @version 0.1.0
 * @date 2022-01-07
 * @copyright Copyright (c) 2022
 * @brief Tests the basic configuration aspects of the main entry point
 * of the whole framework
 */

#include <gtest/gtest.h>
import Wex;


/// Tests the mock fn declared inside the interface module file `.ixx`
/// and implementend in the implementation file '.cpp' in order to know 
/// if all the project's configuration it's correctly seted up
///
/// This test it's merelly provisional, just to assert the correct integration
/// bewteen all the components, including the newly C++20 standard modules
/// the CMake files of the project, the tests subdirectory and it's integration
/// with the `googletest` framework...
TEST(WexTests, checkCPP20ModulesCorrectConfiguration) {
    // If all it's correctly configurated, we should assert the 
    // return value of the function
    EXPECT_EQ(0, foo());
    EXPECT_GT(11, foo() + 10);
}
