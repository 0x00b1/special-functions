#ifndef SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_E_H

namespace detail {
    template<typename T>
    T
    complete_elliptic_integral_e(T k) {
        using U = num_traits_t<T>;

        if (std::isnan(k)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(k) == U{1}) {
            return T{1};
        }

        if (std::abs(k) > U{1}) {
            throw std::domain_error("`k` must be in [-1, 1]");
        }

        const auto r_f = carlson_elliptic_r_f(T{0}, T{1} - k * k, T{1});
        const auto r_d = carlson_elliptic_r_d(T{0}, T{1} - k * k, T{1});

        return r_f - k * k * r_d / T{3};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_E_H
