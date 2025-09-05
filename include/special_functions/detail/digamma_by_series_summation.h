#ifndef SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_BY_SERIES_SUMMATION_H
#define SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_BY_SERIES_SUMMATION_H

namespace detail {
    template<typename Tp>
    Tp
    digamma_by_series_summation(Tp x) {
        using Val = num_traits_t<Tp>;

        Tp sum = -std::numbers::egamma_v<Val>;

        const unsigned int s_max_iter = 100000;

        for (unsigned int k = 0; k < s_max_iter; ++k) {
            const auto term = (x - Tp{1}) / (Tp(k + 1) * (Tp(k) + x));

            sum += term;

            if (std::abs(term) < std::numeric_limits<Val>::epsilon()) {
                break;
            }
        }

        return sum;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_BY_SERIES_SUMMATION_H
