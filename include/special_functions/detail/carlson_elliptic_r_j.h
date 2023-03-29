#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_J_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_J_H

namespace special_functions::detail {
    /**
 * @brief  Return the Carlson elliptic function @f$ R_J(x,y,z,p) @f$
 * 	     of the third kind.
 *
 * The Carlson elliptic function of the third kind is defined by:
 * @f[
 * 	 R_J(x,y,z,p) = \frac{3}{2} \int_0^\infty
 * 	 \frac{dt}{(t + x)^{1/2}(t + y)^{1/2}(t + z)^{1/2}(t + p)}
 * @f]
 *
 * Based on Carlson's algorithms:
 * -  B. C. Carlson Numer. Math. 33, 1 (1979)
 * -  B. C. Carlson, Special Functions of Applied Mathematics (1977)
 * -  Numerical Recipes in C, 2nd ed, pp. 261-269,
 * 	by Press, Teukolsky, Vetterling, Flannery (1992)
 *
 * @param  x  The first of three symmetric arguments.
 * @param  y  The second of three symmetric arguments.
 * @param  z  The third of three symmetric arguments.
 * @param  p  The fourth argument.
 * @return  The Carlson elliptic function of the fourth kind.
 */
    template<typename Tp>
    Tp
    ellint_rj(Tp x, Tp y, Tp z, Tp p)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(Real{});
        const auto s_min = emsr::lim_min(Real{});
        const auto s_eps = emsr::epsilon(Real{});
        const auto s_lolim = Real(5) * s_min;

        bool neg_arg = false;
        if constexpr (!emsr::is_complex_v<Tp>)
            if (std::real(x) < Real{0}
                || std::real(y) < Real{0}
                || std::real(z) < Real{0})
                neg_arg = true;

        if (std::isnan(x) || std::isnan(y) || std::isnan(z) || std::isnan(p))
            return s_NaN;
        else if (neg_arg)
            throw std::domain_error("ellint_rj: argument less than zero");
        else if (std::abs(x) + std::abs(y) < s_lolim
                 || std::abs(y) + std::abs(z) < s_lolim
                 || std::abs(z) + std::abs(x) < s_lolim
                 || std::abs(p) < s_lolim)
            throw std::domain_error("ellint_rj: argument too small");
        else if (std::abs(p - z) < s_eps)
            return ellint_rd(x, y, z);
        else
        {
            auto xt = x;
            auto yt = y;
            auto zt = z;
            auto pt = p;
            auto A0 = (x + y + z + Real{2} * p) / Real{5};
            auto delta = (p - x) * (p - y) * (p - z);
            auto Q = std::pow(s_eps / Real{4}, -Real{1} / Real{6})
                     * std::max(std::abs(A0 - z),
                                std::max(std::abs(A0 - x),
                                         std::max(std::abs(A0 - y), std::abs(A0 - p))));
            auto A = A0;
            auto f = Real{1};
            auto fe = Real{1};
            auto sum = Tp{0};

            while (true)
            {
                auto xroot = std::sqrt(xt);
                auto yroot = std::sqrt(yt);
                auto zroot = std::sqrt(zt);
                auto proot = std::sqrt(pt);
                auto lambda = xroot * yroot
                              + yroot * zroot
                              + zroot * xroot;
                A = (A + lambda) / Real{4};
                xt = (xt + lambda) / Real{4};
                yt = (yt + lambda) / Real{4};
                zt = (zt + lambda) / Real{4};
                pt = (pt + lambda) / Real{4};
                auto d = (proot + xroot)
                         * (proot + yroot)
                         * (proot + zroot);
                auto E = delta / (fe * d * d);
                sum += ellint_rc(Tp{1}, Tp{1} + E) / (f * d);
                f *= Real{4};
                fe *= Real{64};
                if (Q < f * std::abs(A))
                {
                    auto Xi = (A0 - x) / (f * A);
                    auto Yi = (A0 - y) / (f * A);
                    auto Zi = (A0 - z) / (f * A);
                    auto XYZ = Xi * Yi * Zi;
                    auto Pi = -(Xi + Yi + Zi) / Real{2};
                    auto PP = Pi * Pi;
                    auto PPP = PP * Pi;
                    auto E2 = Xi * Yi
                              + Yi * Zi
                              + Zi * Xi
                              - Real{3} * PP;
                    auto E3 = XYZ + Real{2} * E2 * Pi + Tp{4} * PPP;
                    auto E4 = Pi
                              * (Real{2} * XYZ + E2 * Pi + Real{3} * PPP);
                    auto E5 = XYZ * PP;
                    return (Real{1} - Real{3} * E2 / Real{14}
                            + E3 / Real{6}
                            + Real{9} * E2 * E2 / Real{88}
                            - Real{3} * E4 / Real{22}
                            - Real{9} * E2 * E3 / Real{52}
                            + Real{3} * E5 / Real{26}) / f / A / std::sqrt(A)
                           + Real{6} * sum;
                }
            }

            return Tp{};
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_J_H
