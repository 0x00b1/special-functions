#ifndef SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_S_H
#define SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_S_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    neville_theta_s(Tp k, Tp x) {
        using Real = special_functions::num_traits_t<Tp>;
        const auto s_NaN = std::numeric_limits<Tp>::quiet_NaN();
        const auto s_pi_2 = std::numbers::pi_v<Real> / Real{2};

        if (std::isnan(k) || std::isnan(x))
            return s_NaN;
        else if (std::abs(k) > Tp{1})
            throw std::domain_error("theta_s: argument k out of range");
        else {
            const auto kc = std::sqrt(Tp{1} - k * k);
            const auto _Kk = special_functions::comp_ellint_1(k);
            const auto q = ellnome(k);
            return std::sqrt(s_pi_2 / (k * kc * _Kk))
                   * theta_1(q, s_pi_2 * x / _Kk);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_S_H
