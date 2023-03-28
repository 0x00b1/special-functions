#ifndef SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_EI_H
#define SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_EI_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    exponential_integral_ei(Tp x)
    {
        const auto s_eps = emsr::epsilon(x);
        if (x < Tp{0})
            return -expint_E1(-x);
        else if (x < -std::log(s_eps))
            return expint_Ei_series(x);
        else
            return expint_Ei_asymp(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_EI_H
