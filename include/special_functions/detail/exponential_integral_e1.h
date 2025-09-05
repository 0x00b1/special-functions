#ifndef SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E1_H
#define SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E1_H

#include "exponential_integral_e1_by_asymptotic_expansion.h"
#include "exponential_integral_e1_by_series_summation.h"
#include "exponential_integral_e_by_continued_fractions.h"
#include "exponential_integral_ei.h"

namespace detail {
    template<typename T>
    T
    exponential_integral_e1(T x) {
        if (x < T{0}) {
            return -exponential_integral_ei(-x);
        }

        if (x < T{1}) {
            return exponential_integral_e1_by_series_summation(x);
        }

        if (x < T{100}) {
            return exponential_integral_e_by_continued_fractions(1, x);
        }

        return exponential_integral_e1_by_asymptotic_expansion(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E1_H
