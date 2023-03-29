#ifndef SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_E_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    complete_elliptic_integral_e(Tp k)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(k);

        if (std::isnan(k))
            return s_NaN;
        else if (std::abs(k) == Real{1})
            return Tp{1};
        else if (std::abs(k) > Real{1})
            throw std::domain_error("comp_ellint_2: bad argument");
        else
        {
            const auto kk = k * k;

            return ellint_rf(Tp{0}, Tp{1} - kk, Tp{1})
                   - kk * ellint_rd(Tp{0}, Tp{1} - kk, Tp{1})
                     / Tp{3};
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_E_H
