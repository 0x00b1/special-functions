#ifndef SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_K_H
#define SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_K_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    comp_ellint_1(Tp k)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(k);

        if (std::isnan(k))
            return s_NaN;
        else if (std::abs(k) == Real{1})
            return s_NaN;
        else
            return comp_ellint_rf(Tp{1} - k * k, Tp{1});
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_K_H
