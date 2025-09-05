#ifndef SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
#define SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H

namespace detail {
    template<typename T>
    T
    bulirsch_elliptic_integral_el1(T x, T k_c) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(x) || std::isnan(k_c)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        const auto r_f = carlson_elliptic_r_f(T{1}, T{1} + k_c * k_c * (x * x), T{1} + x * x);

        return x * r_f;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
