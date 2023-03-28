#ifndef SPECIAL_FUNCTIONS_DETAIL_TANH_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_TANH_PI_H

namespace special_functions::detail {
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

        const auto a = std::tanh(std::numbers::pi_v<V> * std::real(z));
        const auto b = tan_pi(std::imag(z));

        return (a + std::complex<T>{0, 1} * b) / (U{1} + std::complex<T>{0, 1} * a * b);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_TANH_PI_H
