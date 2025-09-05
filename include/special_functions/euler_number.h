#ifndef SPECIAL_FUNCTIONS_EULER_NUMBER_H
#define SPECIAL_FUNCTIONS_EULER_NUMBER_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/euler_number.h>

namespace special_functions {
    template<typename T>
    T
    euler_number(unsigned int n) {
        return n;
    }
}

#endif // SPECIAL_FUNCTIONS_EULER_NUMBER_H
