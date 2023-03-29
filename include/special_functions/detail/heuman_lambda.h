#ifndef SPECIAL_FUNCTIONS_DETAIL_HEUMAN_LAMBDA_H
#define SPECIAL_FUNCTIONS_DETAIL_HEUMAN_LAMBDA_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    heuman_lambda(Tp k, Tp phi)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(k);
        const auto s_pi = emsr::pi_v<Tp>;
        const auto s_pi_2 = emsr::pi_v<Tp> / Tp{2};
        const auto s_eps = emsr::epsilon(k);

        if (std::isnan(k) || std::isnan(phi))
            return s_NaN;
        else if (std::abs(k) > Tp{1})
            throw std::domain_error("heuman_lambda: bad argument");
        else if (std::abs(std::abs(k) - Tp{1}) < s_eps)
            return phi / s_pi_2;
        else if (std::abs(k) < s_eps)
            return std::sin(phi);
        else if (std::real(phi) < Real{0})
            return -heuman_lambda(k, -phi);
        else if (std::abs(phi - s_pi_2) < Tp{5} * s_eps)
            return Tp{1};
        else if (std::abs(phi) < Tp{5} * s_eps)
            return Tp{0};
        else if (std::abs(phi) < s_pi_2)
        {
            auto mc = k * k;
            auto m = Tp{1} - mc;
            auto cosphi = std::cos(phi);
            auto sinphi = std::sin(phi);
            auto Delta2 = Tp{1} - m * sinphi * sinphi;
            if (std::abs(Delta2) < Real{0})
                Delta2 = Tp{0};
            auto fact = Tp{2} * m * cosphi * sinphi
                        / (s_pi * std::sqrt(Delta2));
            auto arg4 = Tp{1} - mc / Delta2;
            auto fact2 = mc / (Tp{3} * Delta2);

            return fact * (ellint_rf(Tp{0}, m, Tp{1})
                           + fact2 * ellint_rj(Tp{0}, m, Tp{1}, arg4));
        }
        else
        {
            auto kc = std::sqrt(Tp{1} - k * k);
            return ellint_1(kc, phi) / comp_ellint_1(kc)
                   + comp_ellint_1(k) * jacobi_zeta(kc, phi) / s_pi_2;
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_HEUMAN_LAMBDA_H
