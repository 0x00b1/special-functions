#ifndef SPECIAL_FUNCTIONS_DETAIL_JACOBI_ZETA_H
#define SPECIAL_FUNCTIONS_DETAIL_JACOBI_ZETA_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    jacobi_zeta(Tp k, Tp phi)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(k);
        const auto s_pi_2 = emsr::pi_v<Tp> / Tp{2};
        const auto s_eps = emsr::epsilon(k);

        if (std::isnan(k) || std::isnan(phi))
            return s_NaN;
        else if (std::abs(k) > Real{1})
            throw std::domain_error("jacobi_zeta: bad argument");
        else if (std::abs(k) < s_eps)
            return Tp{0};
        else if (std::abs(k - Real{1}) < s_eps)
            return std::sin(phi);
        else if (std::real(phi) < Real{0})
            return -jacobi_zeta(k, -phi);
        else if (std::abs(phi) < s_eps || std::abs(phi - s_pi_2) < s_eps)
            return Tp{0};
        else
        {
            auto mc = k * k;
            auto cosphi = std::cos(phi);
            auto sinphi = std::sin(phi);
            auto m = Tp{1} - mc;
            auto arg4 = Tp{1} - mc  * sinphi * sinphi;
            return mc * cosphi * sinphi * std::sqrt(arg4)
                   * ellint_rj(Tp{0}, m, Real{1}, arg4)
                   / (Tp{3} * comp_ellint_1(k));
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_JACOBI_ZETA_H
