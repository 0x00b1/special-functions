#ifndef SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H
#define SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H

namespace special_functions {
    template<typename T>
    inline T
    stirling_number_s_2(unsigned int n, unsigned int m) {
        return special_functions::detail::stirling_number_s_2<T>(n, m);
    }
}

#endif // SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H
