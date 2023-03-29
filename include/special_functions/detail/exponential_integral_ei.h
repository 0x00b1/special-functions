#ifndef SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_EI_H
#define SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_EI_H

namespace special_functions::detail {
    template<typename T>
    T
    exponential_integral_ei(T x) {
        if (x < T{0}) {
            return -expint_E1(-x);
        }

        if (x < -std::log(std::numeric_limits<T>::epsilon())) {
            return expint_Ei_series(x);
        }

        return expint_Ei_asymp(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_EI_H
