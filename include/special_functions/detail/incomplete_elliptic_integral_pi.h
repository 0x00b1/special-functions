#ifndef SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H

namespace detail {
    template<typename T>
    T
    incomplete_elliptic_integral_pi(T k, T n, T p) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(k) || std::isnan(n) || std::isnan(p)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(k) > U{1}) {
            throw std::domain_error("ellint_3: bad argument");
        }

        const auto floor = std::floor(std::real(p) / std::numbers::pi_v<U> + U{0.5L});

        const auto sin = std::sin(p - floor * std::numbers::pi_v<U>);
        const auto cos = std::cos(p - floor * std::numbers::pi_v<U>);

        const auto r_f = ellint_rf(cos * cos, T{1} - k * k * (sin * sin), T{1});
        const auto r_j = ellint_rj(cos * cos, T{1} - k * k * (sin * sin), T{1}, T{1} - n * (sin * sin));

        if (floor == 0) {
            return sin * r_f + n * (sin * sin * sin) * r_j / T{3};
        }

        return sin * r_f + n * (sin * sin * sin) * r_j / T{3} + T{2} * floor * complete_elliptic_integral_pi(k, n);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H
