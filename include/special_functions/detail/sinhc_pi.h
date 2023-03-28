#ifndef SPECIAL_FUNCTIONS_DETAIL_SINHC_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_SINHC_PI_H

namespace special_functions::detail {
    template<typename Tp>
    emsr::fp_promote_t<Tp>
    sinhc_pi(Tp x)
    {
        const auto s_pi = emsr::pi_v<Tp>;
        if (std::isnan(x))
            return emsr::quiet_NaN(x);
        else
        {
            auto arg = s_pi * x;
            if (std::abs(arg) < Tp{4} * emsr::sqrt_min(x))
                return Tp{1} + arg * arg / Tp{6};
            else
                return emsr::sinh_pi(x) / arg;
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SINHC_PI_H
