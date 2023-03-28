#ifndef SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E_H

#include "exponential_integral_e1.h"
#include "exponential_integral_e_by_asymptotic_expansion.h"
#include "exponential_integral_e_by_continued_fractions.h"
#include "exponential_integral_e_by_recursion.h"
#include "exponential_integral_e_by_series_summation.h"

namespace special_functions::detail {
    template<typename T>
    T
    exponential_integral_e(unsigned int n, T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (n <= 1 && x == T{0}) {
            return std::numeric_limits<T>::infinity();
        }

        if (n == 0) {
            return std::exp(-x) / x;
        }

        if (n == 1) {
            return exponential_integral_e1(x);
        }

        if (x == T{0}) {
            return T{1} / static_cast<T>(n - 1);
        }

        if (x < T{1}) {
            return exponential_integral_e_by_series_summation(n, x);
        }

        if (n > 50000) {
            return expint_En_large_n(n, x);
        }

        if (x > T{100}) {
            return exponential_integral_e_by_asymptotic_expansion(n, x);
        }

        return exponential_integral_e_by_continued_fractions(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E_H
