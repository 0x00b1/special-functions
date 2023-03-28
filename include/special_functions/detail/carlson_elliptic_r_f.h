#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_F_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_F_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    comp_ellint_rf(Tp x, Tp y)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(Real{});
        const auto s_pi = emsr::pi_v<Real>;
        const auto s_tolfact = Real{2.7L} * emsr::sqrt_eps(Real{});

        if (std::isnan(x) || std::isnan(y))
            return s_NaN;
        else
        {
            x = std::sqrt(x);
            y = std::sqrt(y);
            while (true)
            {
                auto xt = x;
                x = (x + y) / Real{2};
                y = std::sqrt(xt) * std::sqrt(y);
                if (std::abs(x - y) < s_tolfact * std::abs(x))
                    return s_pi / (x + y);
            }
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_F_H
