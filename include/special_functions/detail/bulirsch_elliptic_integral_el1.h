#ifndef SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
#define SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    ellint_el1(Tp x, Tp k_c)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(Real{});

        if (std::isnan(x) || std::isnan(k_c))
            return s_NaN;
        else
        {
            auto x2 = x * x;
            auto k2_c = k_c * k_c;
            auto arg2 = Tp{1} + k2_c * x2;
            return x * ellint_rf(Tp{1}, arg2, Tp{1} + x2);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
