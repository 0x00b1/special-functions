#ifndef SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_N_H
#define SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_N_H

namespace detail {
    template<typename T>
    T
    neville_theta_n(T k, T x) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(k) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(k) > T{1}) {
            throw std::domain_error("neville_theta_n: `k` must be in [-1, 1]");
        }

        return std::sqrt(std::numbers::pi_v<U> / U{2} / (std::sqrt(T{1} - k * k) * complete_elliptic_integral_k(k))) * theta_4(nome_q(k), std::numbers::pi_v<U> / U{2} * x / complete_elliptic_integral_k(k));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_N_H
