#ifndef SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H
#define SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H

#include <special_functions/detail/stirling_number_s_2.h>

namespace special_functions {
    template<typename T>
    T
    stirling_number_s_2(unsigned int n, unsigned int m) {
        return detail::stirling_number_s_2<T>(n, m);
    }
}

#endif // SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H
