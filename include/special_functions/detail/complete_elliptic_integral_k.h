#ifndef SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_K_H
#define SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_K_H

namespace special_functions::detail {
    template<typename T>
    T
    complete_elliptic_integral_k(T k) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(k)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(k) == U{1}) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        return complete_carlson_elliptic_r_f(T{1} - k * k, T{1});
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_K_H
