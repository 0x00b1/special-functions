#include <gtest/gtest.h>

#include "special_functions.h"

TEST(cos_pi_test, accuracy) {
    EXPECT_EQ(special_functions::cos_pi(1.0), -1.0);
}

TEST(cosh_pi_test, accuracy) {
    EXPECT_DOUBLE_EQ(special_functions::cosh_pi(1.0), 11.591953275521519);
}

TEST(factorial_test, accuracy) {
    EXPECT_EQ(special_functions::factorial<double>(1), 1.0);
}

TEST(sin_pi_test, accuracy) {
    EXPECT_EQ(special_functions::sin_pi(1.0), -0.0);
}

TEST(sinh_pi_test, accuracy) {
    EXPECT_DOUBLE_EQ(special_functions::sinh_pi(1.0), 11.548739357257746);
}

TEST(tan_pi_test, accuracy) {
    EXPECT_EQ(special_functions::tan_pi(1.0), -0.0);
}

TEST(tanh_pi_test, accuracy) {
    EXPECT_DOUBLE_EQ(special_functions::tanh_pi(1.0), 0.99627207622074998);
}
