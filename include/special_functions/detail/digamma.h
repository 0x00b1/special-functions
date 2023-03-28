#ifndef SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_H

#include "math_constants.h"
#include "math_util.h"
#include "../tan_pi.h"
#include "digamma_by_asymptotic_expansion.h"

namespace special_functions::detail {
    template<typename T>
    T
    digamma(unsigned int n) {
        using U = special_functions::num_traits_t<T>;

        if (n > 1) return -std::numbers::egamma_v<U> + harmonic_number<U>(n - 1);

        return -std::numbers::egamma_v<U>;
    }


    template<typename T>
    T
    digamma(T x) {
        using U = special_functions::num_traits_t<T>;

        const auto is_integer_x = special_functions::fp_is_integer(x);

        const auto is_half_odd_integer_x = special_functions::fp_is_half_odd_integer(x);

        if (std::real(x) <= U{0}) {
            if (is_integer_x) {
                return std::numeric_limits<T>::quiet_NaN();
            }

            return digamma(U{1} - x) - special_functions::pi_v<U> / special_functions::tan_pi(x);
        }

        if (is_integer_x) {
            return digamma<T>(is_integer_x());
        }

        if (is_half_odd_integer_x) {
            T v = -std::numbers::egamma_v<U> - T{2} * special_functions::ln2_v<U>;

            for (int k = 1; k <= is_half_odd_integer_x(); k++) {
                v += T{2} / T(2 * k - 1);
            }

            return v;
        }

        if (std::real(x) > U{20}) {
            return digamma_by_asymptotic_expansion(x);
        }

        auto w = T{0};
        auto y = x;

        while (std::real(y) <= U{20}) {
            w += U{1} / y;
            y += U{1};
        }

        return digamma_by_asymptotic_expansion(y) - w;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_H
