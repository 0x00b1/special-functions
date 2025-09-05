#ifndef SPECIAL_FUNCTIONS_DETAIL_POLYGAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_POLYGAMMA_H

namespace detail {
    template<typename T>
    T
    polygamma(unsigned int m, T x) {
        if (m == 0) {
            return digamma(x);
        }

        if (const auto n = fp_is_integer(x); n && n() <= 0) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        const auto v = std::exp(log_gamma(T(m + 1))) * hurwitz_zeta(T(m + 1), x);

        if (m % 2 == 0) {
            return -v;
        }

        return v;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_POLYGAMMA_H
