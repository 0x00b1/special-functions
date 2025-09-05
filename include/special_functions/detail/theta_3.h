#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_3_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_3_H

#include "theta_3_by_asymptotic_series_expansion.h"
#include "theta_3_by_series_summation.h"

namespace detail {
    template<typename T>
    T
    theta_3(T n, T x) {
        using U = num_traits_t<T>;

        if (std::isnan(n) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(x) <= U{1} / std::numbers::pi_v<U>) {
            return theta_3_by_series_summation(n, x);
        }

        return theta_3_by_asymptotic_series_expansion(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_3_H
