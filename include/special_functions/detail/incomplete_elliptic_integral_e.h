#ifndef SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H

namespace detail {
    template<typename T>
    T
    incomplete_elliptic_integral_e(T k, T p) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(k) || std::isnan(p)) {
            return std::numeric_limits<T>::quiet_NaN(k);
        }

        if (std::abs(k) > U{1}) {
            throw std::domain_error("ellint_2: bad argument");
        }

        const auto n = std::floor(std::real(p) / std::numbers::pi_v<U> + U{0.5L});

        const auto reduction = p - n * std::numbers::pi_v<U>;

        const auto sin = std::sin(reduction);
        const auto cos = std::cos(reduction);

        const auto r_f = ellint_rf(cos * cos, T{1} - k * k * (sin * sin), T{1});
        const auto r_d = ellint_rd(cos * cos, T{1} - k * k * (sin * sin), T{1});

        if (n == 0) {
            return sin * r_f - k * k * (sin * sin * sin) * r_d / T{3};
        }

        return sin * r_f - k * k * (sin * sin * sin) * r_d / T{3} + T{2} * n * complete_elliptic_integral_e(k);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
