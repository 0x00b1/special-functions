#ifndef SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_BY_SERIES_EXPANSION_H
#define SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_BY_SERIES_EXPANSION_H

namespace special_functions::detail {
    template<typename T>
    T
    stirling_number_s_2_by_series_expansion(unsigned int n, unsigned int m) {
        using special_functions::numbers::MAXIMUM_FACTORIAL_INDEX;

        if (m > MAXIMUM_FACTORIAL_INDEX<T>) {
            auto v = T{0};

            for (auto k = 0u; k <= m; k++) {
                if ((m - k) & 1) {
                    v += T{-1} * std::exp(n * std::log(k) - log_factorial<T>(k) - log_factorial<T>(m - k));
                } else {
                    v += T{1} * std::exp(n * std::log(k) - log_factorial<T>(k) - log_factorial<T>(m - k));
                }
            }

            return v;
        }

        auto v = T{0};

        for (auto k = 0u; k <= m; k++) {
            if ((m - k) & 1) {
                v += T{-1} * std::pow(k, n) / factorial<T>(k) / factorial<T>(m - k);
            } else {
                v += T{1} * std::pow(k, n) / factorial<T>(k) / factorial<T>(m - k);
            }
        }

        return std::nearbyint(v);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_BY_SERIES_EXPANSION_H
