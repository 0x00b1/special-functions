#ifndef SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_1_BY_RECURSION_H
#define SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_1_BY_RECURSION_H

namespace detail {
    template<typename T>
    T
    stirling_number_s_1_by_recursion(unsigned int n, unsigned int m) {
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
            for (auto k = 1u; k <= m; k++) {
                current[k] = previous[k - 1] - j * previous[k];
            }

            std::swap(previous, current);
        }

        return current[m];
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_1_BY_RECURSION_H
