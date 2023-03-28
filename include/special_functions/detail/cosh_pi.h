#ifndef SPECIAL_FUNCTIONS_DETAIL_COSH_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_COSH_PI_H

namespace special_functions::detail {
    template<typename T>
    T
    cosh_pi(T x) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(x)) return std::numeric_limits<T>::quiet_NaN();

        if (x < T{0}) return cosh_pi(-x);

        return std::cosh(std::numbers::pi_v<U> * x);
    }

    template<typename T>
    std::complex<T>
    cosh_pi(std::complex<T> z) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        return std::cosh(std::numbers::pi_v<V> * std::real(z)) * cos_pi(std::imag(z)) + std::complex<T>{0, 1} * std::sinh(std::numbers::pi_v<V> * std::real(z)) * sin_pi(std::imag(z));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COSH_PI_H
