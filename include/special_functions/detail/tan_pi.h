#ifndef SPECIAL_FUNCTIONS_DETAIL_TAN_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_TAN_PI_H

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

        const auto a = tan_pi(std::real(z));
        const auto b = std::tanh(std::numbers::pi_v<V> * std::imag(z));

        return (a + std::complex<T>{0, 1} * b) / (U{1} - std::complex<T>{0, 1} * a * b);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_TAN_PI_H
