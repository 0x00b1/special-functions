#ifndef SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_N_H
#define SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_N_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    neville_theta_n(Tp k, Tp x)
    {
        using Real = special_functions::num_traits_t<Tp>;
        const auto s_NaN = std::numeric_limits<Tp>::quiet_NaN();
        const auto s_pi_2 = std::numbers::pi_v<Real> / Real{2};

        if (std::isnan(k) || std::isnan(x))
            return s_NaN;
        else if (std::abs(k) > Tp{1})
            throw std::domain_error("theta_n: argument k out of range");
        else
        {
            const auto kc = std::sqrt(Tp{1} - k * k);
            const auto _Kk = special_functions::comp_ellint_1(k);
            const auto q = ellnome(k);
            return std::sqrt(s_pi_2 / (kc * _Kk))
                   * theta_4(q, s_pi_2 * x / _Kk);
        }
    }

}

#endif // SPECIAL_FUNCTIONS_DETAIL_NEVILLE_THETA_N_H
