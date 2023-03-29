#ifndef SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_S_H
#define SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_S_H

namespace special_functions::detail {
    template<typename T>
    T
    neville_theta_s(T k, T x) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(k) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(k) > T{1}) {
            throw std::domain_error("neville_theta_s: `k` must be in [-1, 1]");
        }

        return std::sqrt(std::numbers::pi_v<U> / U{2} / (k * std::sqrt(T{1} - k * k) * special_functions::complete_elliptic_integral_k(k))) * theta_1(nome_q(k), std::numbers::pi_v<U> / U{2} * x / special_functions::complete_elliptic_integral_k(k));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_S_H
