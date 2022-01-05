#include <gtest/gtest.h>

/**
 * Let's gonna say that you have a bunch of tests that requires the exactly
 * same initial configuration, or depends on some common configurate.
 * 
 * We can create a fixture, This is a structure (or class) for sharing that common config.
 * 
 * It should inherit from a special class of the GoogleTestSuite, in order to make it visible
 * for the testing framework.
 * 
 * Then, you can override the base provided methods in order to achieve some custom 
 * behaviour that fit your needs, like the starting configuration
 * or to automatically delete allocated memory
 */
struct FixtureWexTestsExample : public::testing::Test {

    // Let's assume that we have some complicated member, like a raw pointer. Will use a basic datatype for simplicity
    int *x;

    // Here we set up the initial shared config
    virtual void SetUp() override {
        x = new int {10};  // Dynamically allocating memory for the member
    }

    virtual void TearDown() override {
        // Automatically deletes any allocated memory, preventing posible memory leaks, or do whatever operation after running the tests 
        delete x;
    }
};

// In order to get access to the defined configuration, TEST_F macro should be used on the test declaration
TEST_F(FixtureWexTestsExample, UsingOfSharedConfigurationBehaviour) {
    int x_declared_value = *x; // We directly have access to the 'x' member declared on the configuration structure.
    EXPECT_EQ(11, ++x_declared_value);
}