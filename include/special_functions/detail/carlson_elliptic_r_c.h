#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_C_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_C_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    ellint_rc(Tp x, Tp y)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(Real{});
        const auto s_min = emsr::lim_min(Real{});
        const auto s_eps = emsr::epsilon(Real{});
        const auto s_lolim = Real{5} * s_min;

        bool neg_x = false, neg_y = false;
        if constexpr (!emsr::is_complex_v<Tp>)
        {
            if (std::real(x) < Real{0})
                neg_x = true;
            if (std::real(y) < Real{0})
                neg_y = true;
        }

        if (std::isnan(x) || std::isnan(y))
            return s_NaN;
        else if (neg_x)
            throw std::domain_error("ellint_rc: argument less than zero");
        else if (std::abs(x) + std::abs(y) < s_lolim)
            throw std::domain_error("ellint_rc: arguments too small");
        else if (neg_y)
        {
            if (std::abs(x) == Real{0})
                return Tp{};
            else
                return std::sqrt(x / (x - y)) * ellint_rc(x - y, -y);
        }
        else
        {
            auto xt = x;
            auto yt = y;
            auto A0 = (x + Real{2} * y) / Real{3};
            auto Q = std::pow(Real{3} * s_eps, -Real{1} / Real{8})
                     * std::abs(A0 - x);
            auto A = A0;
            auto f = Real{1};

            while (true)
            {
                auto lambda = Real{2} * std::sqrt(xt) * std::sqrt(yt)
                              + yt;
                A = (A + lambda) / Real{4};
                xt = (xt + lambda) / Real{4};
                yt = (yt + lambda) / Real{4};
                f *= Real{4};
                if (Q < f * std::abs(A))
                {
                    auto s = (y - A0) / (f * A);
                    return (Real{1} + s * s * (Real{3} / Real{10}
                                               + s * (Real{1} / Real{7}
                                                      + s * (Real{3} / Real{8}
                                                             + s * (Real{9} / Real{22}
                                                                    + s * (Real{159} / Real{208}
                                                                           + s * (Real{9} / Real{8}))))))) / std::sqrt(A);
                }
            }

            return Tp{0};
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_C_H
