#ifndef SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_PI_H

namespace detail {
    template<typename T>
    T
    complete_elliptic_integral_pi(T k, T n) {
        using U = num_traits_t<T>;

        if (std::isnan(k) || std::isnan(n)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (n == T{1}) {
            return std::numeric_limits<T>::infinity();
        }

        if (std::abs(k) > U{1}) {
            throw std::domain_error("`k` must be in [-1, 1]");
        }

        const auto r_f = carlson_elliptic_r_f(T{0}, T{1} - k * k, T{1});
        const auto r_j = carlson_elliptic_r_j(T{0}, T{1} - k * k, T{1}, T{1} - n);

        return r_f + n * r_j / T{3};
    }

}

#endif // SPECIAL_FUNCTIONS_DETAIL_COMPLETE_ELLIPTIC_INTEGRAL_PI_H
