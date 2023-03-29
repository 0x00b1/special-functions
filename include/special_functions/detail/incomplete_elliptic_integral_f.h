#ifndef SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_F_H
#define SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_F_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    incomplete_elliptic_integral_f(Tp k, Tp phi)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(k);
        const auto s_pi = emsr::pi_v<Real>;

        if (std::isnan(k) || std::isnan(phi))
            return s_NaN;
        else if (std::abs(k) > Real{1})
            throw std::domain_error("ellint_1: bad argument");
        else
        {
            // Reduce phi to -pi/2 < phi < +pi/2.
            const int n = std::floor(std::real(phi) / s_pi + Real{0.5L});
            const auto phi_red = phi - n * s_pi;

            const auto s = std::sin(phi_red);
            const auto c = std::cos(phi_red);

            const auto F = s
                           * ellint_rf(c * c,
                                       Tp{1} - k * k * s * s,
                                       Tp{1});

            if (n == 0)
                return F;
            else
                return F + Tp{2} * n * comp_ellint_1(k);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_ELLIPTIC_INTEGRAL_F_H
