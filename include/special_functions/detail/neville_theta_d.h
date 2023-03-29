#ifndef SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_D_H
#define SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_D_H

namespace special_functions::detail {
    template<typename T>
    T
    neville_theta_d(T k, T x) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(k) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(k) > T{1}) {
            throw std::domain_error("theta_d: argument k out of range");
        }

        const auto k_k = special_functions::complete_elliptic_integral_k(k);

        const auto pi_2 = std::numbers::pi_v<U> / U{2};

        return std::sqrt(pi_2 / k_k) * theta_3(nome_q(k), pi_2 * x / k_k);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_D_H
