#ifndef SPECIAL_FUNCTIONS_DETAIL_EULERIAN_NUMBER_2_BY_RECURSION_H
#define SPECIAL_FUNCTIONS_DETAIL_EULERIAN_NUMBER_2_BY_RECURSION_H

namespace special_functions::detail {
    template<typename T>
    T
    eulerian_number_2_by_recursion(unsigned int n, unsigned int m) {
        if (m == 0) {
            return T{1};
        }

        if (m >= n) {
            return T{0};
        }

        if (n == 0) {
            return T{1};
        }

        std::vector<T> previous(m + 1);
        std::vector<T> current(m + 1);

        previous[0] = T{1};

        current[0] = T{1};
        current[1] = T{2};

        for (auto j = 3u; j <= n; j++) {
            std::swap(previous, current);

            for (auto k = 1u; k <= m; k++) {
                current[k] = (2 * j - k - 1) * previous[k - 1] + (k + 1) * previous[k];
            }
        }

        return current[m];
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_EULERIAN_NUMBER_2_BY_RECURSION_H
