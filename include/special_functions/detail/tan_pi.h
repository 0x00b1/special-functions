#ifndef SPECIAL_FUNCTIONS_DETAIL_TAN_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_TAN_PI_H

#include <complex>

#include "special_functions/detail/fp_type_util.h"

namespace special_functions {
    namespace detail {
        template<typename T>
        T
        tan_pi(T x) {
            using U = T;
            using V = special_functions::num_traits_t<U>;

            return std::tan(std::numbers::pi_v<V> * (x - std::floor(x)));
        }

        template<typename T>
        std::complex<T>
        tan_pi(std::complex<T> z) {
            using U = T;
            using V = special_functions::num_traits_t<U>;
            const auto s_pi = std::numbers::pi_v<V>;
            const auto s_i = std::complex<T>{0, 1};
            auto x = std::real(z);
            auto y = std::imag(z);
            auto tan = tan_pi(x);
            auto tanh = std::tanh(s_pi * y);
            return (tan + s_i * tanh) / (U{1} - s_i * tan * tanh);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_TAN_PI_H
