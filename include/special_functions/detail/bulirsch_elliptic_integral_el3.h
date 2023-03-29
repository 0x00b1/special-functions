#ifndef SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H
#define SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    ellint_el3(Tp x, Tp k_c, Tp p)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(Real{});

        if (std::isnan(x) || std::isnan(k_c) || std::isnan(p))
            return s_NaN;
        else
        {
            auto x2 = x * x;
            auto x3 = x * x;
            auto k2_c = k_c * k_c;
            auto arg2 = Tp{1} + k2_c * x2;
            auto arg3 = Tp{1} + x2;
            auto arg4 = Tp{1} + p * x2;
            return x * ellint_rf(Real{1}, arg2, arg3)
                   + (Tp{1} - p) * x3
                     * ellint_rj(Tp{1}, arg2, arg3, arg4) / Tp{3};
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H
