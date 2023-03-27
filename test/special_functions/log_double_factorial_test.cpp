#include <gtest/gtest.h>

#include <special_functions.h>

TEST(log_double_factorial_test, accuracy) {
    EXPECT_EQ(special_functions::log_double_factorial<double>(0.0), 0.0);
}
