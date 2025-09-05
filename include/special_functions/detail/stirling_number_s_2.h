#ifndef SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_H
#define SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_H

#include "stirling_number_s_2_by_recursion.h"
#include "stirling_number_s_2_by_series_expansion.h"

namespace detail {
    template<typename T>
    T
    stirling_number_s_2(unsigned int n, unsigned int m) {
        if (m > n) {
            return T{0};
        }

        if (m == n) {
            return T{1};
        }

        if (m == 0 && n >= 1) {
            return T{0};
        }

        return stirling_number_s_2_by_recursion<T>(n, m);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_H
