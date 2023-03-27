#ifndef SPECIAL_FUNCTIONS_DETAIL_TANH_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_TANH_PI_H

#include <complex>

#include "special_functions/detail/fp_type_util.h"

namespace special_functions {
    namespace detail {
        template<typename T>
        T
        tanh_pi(T x) {
            using U = T;
            using V = special_functions::num_traits_t<U>;

            return std::tanh(std::numbers::pi_v<V> * x);
        }

        template<typename T>
        std::complex<T>
        tanh_pi(std::complex<T> z) {
            using U = T;
            using V = special_functions::num_traits_t<U>;
            const auto s_pi = std::numbers::pi_v<V>;
            const auto s_i = std::complex<T>{0, 1};
            auto x = std::real(z);
            auto y = std::imag(z);
            auto tanh = std::tanh(s_pi * x);
            auto tan = tan_pi(y);
            return (tanh + s_i * tan) / (U{1} + s_i * tanh * tan);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_TANH_PI_H
