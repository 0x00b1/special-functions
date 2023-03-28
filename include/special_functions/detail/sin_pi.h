#ifndef SPECIAL_FUNCTIONS_DETAIL_SIN_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_SIN_PI_H

namespace special_functions::detail {
    template<typename T>
    T
    sin_pi(T x) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(x)) return std::numeric_limits<T>::quiet_NaN();

        if (x < T{0}) return -sin_pi(-x);

        if (x < T{0.5L}) return std::sin(x * std::numbers::pi_v<U>);

        if (x < T{1}) return std::sin((T{1} - x) * std::numbers::pi_v<U>);

        int sign;

        if ((int(std::floor(x)) & 1) == 1) {
            sign = -1;
        } else {
            sign = +1;
        }

        if (x - std::floor(x) < T{0.5L}) return sign * sin_pi(x - std::floor(x));

        return sign * sin_pi(T{1.0} - (x - std::floor(x)));
    }

    template<typename T>
    std::complex<T>
    sin_pi(std::complex<T> z) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        return sin_pi(std::real(z)) * std::cosh(std::numbers::pi_v<V> * std::imag(z)) +
               std::complex<T>{0, 1} * cos_pi(std::real(z)) * std::sinh(std::numbers::pi_v<V> * std::imag(z));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SIN_PI_H
