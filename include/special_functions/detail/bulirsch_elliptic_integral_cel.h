#ifndef SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H
#define SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    ellint_cel(Tp k_c, Tp p, Tp a, Tp b)
    {
        const auto s_NaN = emsr::quiet_NaN(k_c);

        if (std::isnan(k_c) || std::isnan(p) || std::isnan(a) || std::isnan(b))
            return s_NaN;
        else
        {
            auto k2_c = k_c * k_c;
            return a * ellint_rf(Tp{0}, k2_c, Tp{1})
                   + (b - p * a)
                     * ellint_rj(Tp{0}, k2_c, Tp{1}, p) / Tp{3};
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H
