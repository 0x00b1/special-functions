#include <gtest/gtest.h>

#include <special_functions.h>

TEST(cos_pi_test, accuracy) {
    EXPECT_EQ(special_functions::cos_pi(0.0), 1.0);
}

TEST(cosh_pi_test, accuracy) {
    EXPECT_EQ(special_functions::cosh_pi(0.0), 1.0);
}

TEST(double_factorial_test, accuracy) {
    EXPECT_EQ(special_functions::double_factorial<double>(0), 0.0);
}

TEST(factorial_test, accuracy) {
    EXPECT_EQ(special_functions::factorial<double>(0), 1.0);
}

TEST(log_double_factorial_test, accuracy) {
    EXPECT_EQ(special_functions::log_double_factorial<double>(1), 3.6082248300317588e-16);
}

TEST(log_factorial_test, accuracy) {
    EXPECT_EQ(special_functions::log_factorial<double>(0), 0.0);
}

TEST(log_gamma, accuracy) {
    EXPECT_EQ(special_functions::log_gamma(0.0), std::numeric_limits<double>::infinity());
    EXPECT_DOUBLE_EQ(special_functions::log_gamma(0.1), 2.2527126517342051);
}

TEST(log_gamma_sign, accuracy) {
    EXPECT_EQ(special_functions::log_gamma_sign(0.0), 0.0);
}

TEST(sin_pi_test, accuracy) {
    EXPECT_EQ(special_functions::sin_pi(0.0), 0.0);
}

TEST(sinh_pi_test, accuracy) {
    EXPECT_EQ(special_functions::sinh_pi(0.0), 0.0);
}

TEST(tan_pi_test, accuracy) {
    EXPECT_EQ(special_functions::tan_pi(0.0), 0.0);
}

TEST(tanh_pi_test, accuracy) {
    EXPECT_EQ(special_functions::tanh_pi(0.0), 0.0);
}
