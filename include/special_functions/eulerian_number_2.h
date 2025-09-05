#ifndef SPECIAL_FUNCTIONS_EULERIAN_NUMBER_2_H
#define SPECIAL_FUNCTIONS_EULERIAN_NUMBER_2_H

#include <special_functions/detail/eulerian_number_2.h>

namespace special_functions {
    template<typename T>
    T
    eulerian_number_2(unsigned int n, unsigned int m) {
        return detail::eulerian_number_2<T>(n, m);
    }
}

#endif // SPECIAL_FUNCTIONS_EULERIAN_NUMBER_2_H
