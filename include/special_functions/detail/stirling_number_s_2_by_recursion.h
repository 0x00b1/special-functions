#ifndef SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_BY_RECURSION_H
#define SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_BY_RECURSION_H

namespace detail {
    template<typename T>
    T
    stirling_number_s_2_by_recursion(unsigned int n, unsigned int m) {
        if (n == 0) {
            return T(m == 0);
        }

        if (m == 0) {
            return T(n == 0);
        }

        std::vector<T> previous(m + 1);
        std::vector<T> current(m + 1);

        previous[1] = T{1};

        if (n == 1) {
            return previous[m];
        }

        for (auto j = 1u; j <= n; j++) {
            current[1] = previous[1];

            for (auto k = 2u; k <= m; k++) {
                current[k] = k * previous[k] + previous[k - 1];
            }

            std::swap(previous, current);
        }

        return current[m];
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_BY_RECURSION_H
