#ifndef SPECIAL_FUNCTIONS_DETAIL_HEUMAN_LAMBDA_H
#define SPECIAL_FUNCTIONS_DETAIL_HEUMAN_LAMBDA_H

namespace special_functions::detail {
    template<typename T>
    T
    heuman_lambda(T k, T phi)
    {
        using U = special_functions::num_traits_t<T>;
        const auto s_NaN = std::numeric_limits<T>::quiet_NaN();
        const auto s_pi = std::numbers::pi_v<T>;
        const auto s_pi_2 = std::numbers::pi_v<T> / T{2};
        const auto s_eps = std::numeric_limits<T>::epsilon();

        if (std::isnan(k) || std::isnan(phi)) {
            return s_NaN;
        }

        if (std::abs(k) > T{1}) {
            throw std::domain_error("heuman_lambda: bad argument");
        }

        if (std::abs(std::abs(k) - T{1}) < s_eps) {
            return phi / s_pi_2;
        }

        if (std::abs(k) < s_eps) {
            return std::sin(phi);
        }

        if (std::real(phi) < U{0}) {
            return -heuman_lambda(k, -phi);
        }

        if (std::abs(phi - s_pi_2) < T{5} * s_eps) {
            return T{1};
        }

        if (std::abs(phi) < T{5} * s_eps) {
            return T{0};
        }

        if (std::abs(phi) < s_pi_2) {
            auto mc = k * k;
            auto m = T{1} - mc;
            auto cosphi = std::cos(phi);
            auto sinphi = std::sin(phi);
            auto Delta2 = T{1} - m * sinphi * sinphi;
            if (std::abs(Delta2) < U{0}) {
                Delta2 = T{0};
            }

            auto fact = T{2} * m * cosphi * sinphi / (s_pi * std::sqrt(Delta2));
            auto arg4 = T{1} - mc / Delta2;
            auto fact2 = mc / (T{3} * Delta2);

            return fact * (ellint_rf(T{0}, m, T{1}) + fact2 * ellint_rj(T{0}, m, T{1}, arg4));
        }

        auto kc = std::sqrt(T{1} - k * k);
        return ellint_1(kc, phi) / comp_ellint_1(kc) + comp_ellint_1(k) * jacobi_zeta(kc, phi) / s_pi_2;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_HEUMAN_LAMBDA_H
