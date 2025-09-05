#ifndef SPECIAL_FUNCTIONS_DETAIL_COS_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_COS_PI_H

namespace detail {
    template<typename T>
    T
    cos_pi(T x) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(x)) return std::numeric_limits<T>::quiet_NaN();

        if (x < T{0}) return cos_pi(-x);

        if (x < T{0.5L}) return std::cos(x * std::numbers::pi_v<U>);

        if (x < T{1}) return -std::cos((T{1} - x) * std::numbers::pi_v<U>);

        return ((int(std::floor(x)) & 1) == 1 ? -1 : +1) * cos_pi(x - std::floor(x));
    }

    template<typename T>
    std::complex<T>
    cos_pi(std::complex<T> z) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        return cos_pi(std::real(z)) * std::cosh(std::numbers::pi_v<V> * std::imag(z)) -
               std::complex<T>{0, 1} * sin_pi(std::real(z)) * std::sinh(std::numbers::pi_v<V> * std::imag(z));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COS_PI_H
