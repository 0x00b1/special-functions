#ifndef SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_Q_H
#define SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_Q_H

#include "incomplete_gamma_by_continued_fraction.h"
#include "incomplete_gamma_by_series_summation.h"

namespace special_functions::detail {
    template<typename T>
    T
    regularized_gamma_q(T a, T x) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        if (std::isnan(a) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        auto is_integer_a = special_functions::fp_is_integer(a);

        if (is_integer_a && is_integer_a() <= 0) {
            throw std::domain_error("gamma_q: non-positive integer argument a");
        }

        if (std::real(x) < std::real(a + V{1})) {
            return U{1} - incomplete_gamma_by_series_summation(a, x).first;
        }

        return incomplete_gamma_by_continued_fraction(a, x).first;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_Q_H
