#ifndef SPECIAL_FUNCTIONS_DETAIL_EULERIAN_NUMBER_1_H
#define SPECIAL_FUNCTIONS_DETAIL_EULERIAN_NUMBER_1_H

#include "eulerian_number_1_by_recursion.h"

namespace special_functions::detail {
    template<typename T>
    inline T
    eulerian_number_1(unsigned int n, unsigned int m) {
        return eulerian_number_1_by_recursion<T>(n, m);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_EULERIAN_NUMBER_1_H
