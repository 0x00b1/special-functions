#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_D_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_D_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    ellint_rd(Tp x, Tp y, Tp z) {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(Real{});
        const auto s_min = emsr::lim_min(Real{});
        const auto s_eps = emsr::epsilon(Real{});
        const auto s_lolim = Real{5} * s_min;

        bool neg_arg = false;
        if constexpr (!emsr::is_complex_v < Tp >)
            if (std::real(x) < Real{0}
                || std::real(y) < Real{0}
                || std::real(z) < Real{0})
                neg_arg = true;

        if (std::isnan(x) || std::isnan(y) || std::isnan(z))
            return s_NaN;
        if (neg_arg)
            throw std::domain_error("ellint_rd: argument less than zero");
        else if (std::abs(x) + std::abs(y) < s_lolim
                 || std::abs(z) < s_lolim)
            throw std::domain_error("ellint_rd: arguments too small");
        else {
            auto xt = x;
            auto yt = y;
            auto zt = z;
            auto A0 = (x + y + Real{3} * z) / Real{5};
            auto Q = std::pow(s_eps / Real{4}, -Real{1} / Real{6})
                     * std::max(std::abs(A0 - z),
                                std::max(std::abs(A0 - x),
                                         std::abs(A0 - y)));
            auto A = A0;
            auto f = Real{1};
            auto sum = Tp{0};

            while (true) {
                auto lambda = std::sqrt(xt) * std::sqrt(yt)
                              + std::sqrt(yt) * std::sqrt(zt)
                              + std::sqrt(zt) * std::sqrt(xt);
                sum += Real{1} / f / std::sqrt(zt) / (zt + lambda);
                A = (A + lambda) / Real{4};
                xt = (xt + lambda) / Real{4};
                yt = (yt + lambda) / Real{4};
                zt = (zt + lambda) / Real{4};
                f *= Real{4};
                if (Q < f * std::abs(A)) {
                    auto Xi = (A0 - x) / (f * A);
                    auto Yi = (A0 - y) / (f * A);
                    auto Zi = -(Xi + Yi) / Real{3};
                    auto ZZ = Zi * Zi;
                    auto XY = Xi * Yi;
                    auto E2 = XY - Real{6} * ZZ;
                    auto E3 = (Real{3} * XY - Real{8} * ZZ) * Zi;
                    auto E4 = Real{3} * (XY - ZZ) * ZZ;
                    auto E5 = XY * Zi * ZZ;
                    return (Real{1}
                            - Real{3} * E2 / Real{14}
                            + E3 / Real{6}
                            + Real{9} * E2 * E2 / Real{88}
                            - Real{3} * E4 / Real{22}
                            - Real{9} * E2 * E3 / Real{52}
                            + Real{3} * E5 / Real{26}) / f / A / std::sqrt(A)
                           + Real{3} * sum;
                }
            }

            return Tp{0};
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_D_H
