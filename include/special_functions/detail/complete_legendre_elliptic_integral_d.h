#ifndef SPECIAL_FUNCTIONS_DETAIL_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
#define SPECIAL_FUNCTIONS_DETAIL_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H

namespace special_functions::detail {
    template<typename T>
    T
    complete_legendre_elliptic_integral_d(T k) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(k)) {
            return std::numeric_limits<T>::quiet_NaN(k);
        }

        return ellint_rd(T{0}, T{1} - k * k, T{1}) / U{3};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
