#ifndef SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H
#define SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H

namespace special_functions::detail {
    template<typename T>
    T
    bulirsch_elliptic_integral_cel(T k_c, T p, T a, T b) {
        if (std::isnan(k_c) || std::isnan(p) || std::isnan(a) || std::isnan(b)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        const auto r_f = carlson_elliptic_r_f(T{0}, k_c * k_c, T{1});
        const auto r_j = carlson_elliptic_r_j(T{0}, k_c * k_c, T{1}, p);

        return a * r_f + (b - p * a) * r_j / T{3};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H
