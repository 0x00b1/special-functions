#ifndef SPECIAL_FUNCTIONS_DETAIL_COS_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_COS_PI_H

#include <complex>
#include <numbers>

#include "fp_type_util.h"

namespace special_functions {
    namespace detail {
        template<typename T>
        T
        cos_pi(T x) {
            using U = special_functions::num_traits_t<T>;

            const auto s_pi = std::numbers::pi_v<U>;

            if (std::isnan(x)) {
                return std::numeric_limits<T>::quiet_NaN();
            }

            if (x < T{0}) {
                return cos_pi(-x);
            }

            if (x < T{0.5L}) {
                return std::cos(x * s_pi);
            }

            if (x < T{1}) {
                return -std::cos((T{1} - x) * s_pi);
            }

            auto n = std::floor(x);

            auto arg = x - n;

            auto sign = (int(n) & 1) == 1 ? -1 : +1;

            return sign * cos_pi(arg);
        }

        template<typename T>
        std::complex<T>
        cos_pi(std::complex<T> z) {
            using U = T;
            using V = special_functions::num_traits_t<U>;
            const auto s_pi = std::numbers::pi_v<V>;
            const auto s_i = std::complex<T>{0, 1};
            auto x = std::real(z);
            auto y = std::imag(z);
            return cos_pi(x) * std::cosh(s_pi * y) - s_i * sin_pi(x) * std::sinh(s_pi * y);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COS_PI_H
