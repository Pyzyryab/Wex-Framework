#include <gtest/gtest.h>

/**
 * This file was created the same day that this project had been started, on 01/01/2022
 * 
 * Wex Framework it's intended to be many things, but one primary rule that will be applied
 * it's that anything will be developed using a TDD aproach.
 * 
 * GoogleTest will be the tool elected as the testing framework for this project.
 * 
 * Here we'll show some basic examples of usage of the GoogleTest provided stuff, 
 */


// 1 - We are starting by doing some macros sanity checking, just for starting the repo and the tests of Wex,
// making a very small demonstration of usage of GoogleTest
auto lambda_true = [] () { return true; };

TEST(InitialWexTests, ShowGTestBasicMacros) {
    EXPECT_TRUE(true);
    // Assert it's a more restrictive version of expect. If the test runner
    // fails on an assert, it will stops the program. 
    ASSERT_TRUE(true);
    EXPECT_FALSE(false);
    // If the assert_true w'd check a 'false' value, test will fail and compiler
    // never reached line 10.

    // Expected value. Just by convention, here we will use
    // the expect value as first argument, and the actual as second
    EXPECT_EQ(true, lambda_true());
}


/**
 * 2 - Demonstrate how to debug and detect darker potencially side effects problems 
 * derivated from unclear or bad designed code
 * 
 * Let's use a global variable to ilustrate a posible situation and how things can quickly go to hell.
 * void use usage of globals ALWAYS in modern C++ (and in any another language)
*/
int accumulator {0};

TEST(InitialWexTests, CheckSideEffectsEx) {
    // Stores a lambda that will modify the global
    auto bad_boy_lambda = [&] () { accumulator += 10; };
    // Through you code, somebody can call the lambda, that modifies X value
    bad_boy_lambda();
    // But some other part of your code it's assuming that X still have it's original value, and we haven't noticed that the lambda have been called.
    // So know we want to ensure that the value of x it's still the same when it's went initialized, so EXPECT_EQ(x, 0)
    EXPECT_GT(accumulator, 0); // EXPECT_GT Macro it's used now just to pass all the checks when the code it's compillled.
    // But thought if EXPECT_EQ we're used, test will fail, and we can discover a potencial bug in our code, supossing that we are assuming that
    // our x variable haven't been modified until the lambda usage
    EXPECT_EQ(accumulator, 10); // We can test, if we notice about the lambda usage, that it's value its incremented by 10 once

    // Basic usage for loop testing
    for(int i = 0; i < 10; i++)
        EXPECT_LT(i, 10); // This way you can test that the breaking condition it's well applied
        // Every loop you are expecting that the i loop variable don't reaches the breaking condition value

    // We can output some 'debug' information by using the '<<' operation on any behavioural macro
    // Basic usage for loop testing
    for(int i = 0; i < 10; i++)
        EXPECT_LT(i, 10) << "Actual value of loop variable i: " << i;
}