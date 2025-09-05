#ifndef SPECIAL_FUNCTIONS_DETAIL_LAH_NUMBER_H
#define SPECIAL_FUNCTIONS_DETAIL_LAH_NUMBER_H

#include "lah_number_by_recursion.h"

namespace detail {
    template<typename T>
    T
    lah_number(unsigned int n, unsigned int k) {
        return lah_number_by_recursion<T>(n, k);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LAH_NUMBER_H
