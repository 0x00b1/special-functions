#ifndef SPECIAL_FUNCTIONS_DETAIL_SINHC_H
#define SPECIAL_FUNCTIONS_DETAIL_SINHC_H

namespace special_functions::detail {
    template<typename Tp>
    emsr::fp_promote_t<Tp>
    sinhc(Tp x)
    {
        if (std::isnan(x))
            return emsr::quiet_NaN(x);
        else if (std::abs(x) < Tp{4} * emsr::sqrt_min(x))
            return Tp{1} + x * x / Tp{6};
        else
            return std::sinh(x) / x;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SINHC_H
