#ifndef SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H
#define SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H

namespace special_functions::detail {
    template<typename T>
    T
    bulirsch_elliptic_integral_el3(T x, T k_c, T p) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(x) || std::isnan(k_c) || std::isnan(p)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        const auto r_f = carlson_elliptic_r_f(U{1}, T{1} + k_c * k_c * (x * x), T{1} + x * x);
        const auto r_j = carlson_elliptic_r_j(T{1}, T{1} + k_c * k_c * (x * x), T{1} + x * x, T{1} + p * (x * x));

        return x * r_f + (T{1} - p) * (x * x) * r_j / T{3};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H
