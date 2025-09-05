#ifndef SPECIAL_FUNCTIONS_DETAIL_UPPER_INCOMPLETE_GAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_UPPER_INCOMPLETE_GAMMA_H

#include "incomplete_gamma_by_continued_fraction.h"
#include "incomplete_gamma_by_series_summation.h"

namespace detail {
    template<typename T>
    T
    upper_incomplete_gamma(T a, T x) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        if (std::isnan(a) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        auto is_integer_a = fp_is_integer(a);

        if (is_integer_a && is_integer_a() <= 0) {
            throw std::domain_error("upper_incomplete_gamma: a must be a positive integer");
        }

        if (std::real(x) < std::real(a + V{1})) {
            const auto v = incomplete_gamma_by_series_summation(a, x);

            return std::exp(v.second) * (T{1} - v.first);
        }

        const auto v = incomplete_gamma_by_continued_fraction(a, x);

        return std::exp(v.second) * v.first;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_UPPER_INCOMPLETE_GAMMA_H
