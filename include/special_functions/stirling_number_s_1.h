#ifndef SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H
#define SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H


#include <complex>


namespace special_functions {
    template<typename T>
    T
    stirling_number_s_1(unsigned int n, unsigned int m) {
        return detail::stirling_number_s_1<T>(n, m);
    }
}

#endif // SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H
