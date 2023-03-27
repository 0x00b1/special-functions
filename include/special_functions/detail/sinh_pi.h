#ifndef SPECIAL_FUNCTIONS_DETAIL_SINH_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_SINH_PI_H

#include <complex>

#include "fp_type_util.h"

namespace special_functions {
    namespace detail {
        template<typename T>
        T
        sinh_pi(T x) {
            using U = special_functions::num_traits_t<T>;

            if (std::isnan(x)) {
                return std::numeric_limits<T>::quiet_NaN();
            }

            if (x < T{0}) {
                return -sinh_pi(-x);
            }

            return std::sinh(std::numbers::pi_v<U> * x);
        }

        template<typename T>
        std::complex<T>
        sinh_pi(std::complex<T> z) {
            using U = T;
            using V = special_functions::num_traits_t<U>;
            const auto s_pi = std::numbers::pi_v<V>;
            const auto s_i = std::complex<T>{0, 1};
            auto x = std::real(z);
            auto y = std::imag(z);
            return std::sinh(s_pi * x) * cos_pi(y) + s_i * std::cosh(s_pi * x) * sin_pi(y);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SINH_PI_H
