#ifndef SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H
#define SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H

namespace detail {
    template<typename T>
    T
    bulirsch_elliptic_integral_el2(T x, T k_c, T a, T b) {
        using U = num_traits_t<T>;

        if (std::isnan(x) || std::isnan(k_c) || std::isnan(a) || std::isnan(b)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        const auto r_f = carlson_elliptic_r_f(T{1}, T{1} + k_c * k_c * (x * x), T{1} + x * x);
        const auto r_d = carlson_elliptic_r_d(T{1}, T{1} + k_c * k_c * (x * x), T{1} + x * x);

        return a * x * r_f + (b - a) * (x * x) * r_d / T{3};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H
