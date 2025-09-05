#ifndef SPECIAL_FUNCTIONS_DETAIL_BESSEL_BY_SERIES_EXPANSION_H
#define SPECIAL_FUNCTIONS_DETAIL_BESSEL_BY_SERIES_EXPANSION_H

#include <complex>

namespace detail {
    template<typename T, typename U>
    constexpr U
    bessel_by_series_expansion(T n, U x, int sign, unsigned int maximum_iteration) {
        using V = fp_promote_t<T, U>;
        using W = num_traits_t<V>;

        if (std::abs(x) < std::numeric_limits<W>::epsilon()) {
            if (n == T{0}) {
                return U{1};
            }

            return U{0};
        }

        const auto x2 = x / W{2};

        const auto xx4 = V(sign) * x2 * x2;
        auto Jn = V{1};
        auto term = V{1};

        for (unsigned int iteration = 1; iteration < maximum_iteration; iteration++) {
            term *= xx4 / (V(iteration) * (V(n) + V(iteration)));
            Jn += term;

            if (std::abs(term / Jn) < std::numeric_limits<W>::epsilon()) {
                break;
            }
        }

        return std::exp(V(n) * std::log(x2) - log_gamma(W{1} + n)) * Jn;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BESSEL_BY_SERIES_EXPANSION_H
