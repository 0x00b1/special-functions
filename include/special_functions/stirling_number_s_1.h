#ifndef SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H
#define SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H

namespace special_functions {
    template<typename T>
    inline T
    stirling_number_s_1(unsigned int n, unsigned int m) {
        return special_functions::detail::stirling_number_s_1<T>(n, m);
    }
}

#endif // SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H
