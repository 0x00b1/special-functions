#ifndef SPECIAL_FUNCTIONS_DETAIL_LAH_NUMBER_BY_RECURSION_H
#define SPECIAL_FUNCTIONS_DETAIL_LAH_NUMBER_BY_RECURSION_H

namespace special_functions::detail {
    template<typename T>
    T
    lah_number_by_recursion(unsigned int n, unsigned int k)
    {
        if (k > n) {
            return T{0};
        }

        if (n == 0) {
            if (k == 0) {
                return T{1};
            } else {
                return T{0};
            }
        }

        T v = 1;

        for (unsigned int j = 1u; j <= n - k; j++) {
            v *= T(n - j + 1) * T(n - j) / T(j);
        }

        return v;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LAH_NUMBER_BY_RECURSION_H
