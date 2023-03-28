#ifndef SPECIAL_FUNCTIONS_LAH_NUMBER_H
#define SPECIAL_FUNCTIONS_LAH_NUMBER_H

namespace special_functions {
    template<typename T>
    inline T
    lah_number(unsigned int n, unsigned int k) {
        return special_functions::detail::lah_number<T>(n, k);
    }
}

#endif // SPECIAL_FUNCTIONS_LAH_NUMBER_H
