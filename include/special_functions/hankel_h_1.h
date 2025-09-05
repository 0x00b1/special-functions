#ifndef SPECIAL_FUNCTIONS_HANKEL_H_1_H
#define SPECIAL_FUNCTIONS_HANKEL_H_1_H

#include <special_functions/detail/hankel_h_1.h>

namespace special_functions {
    template<typename T, typename U>
    std::complex<fp_promote_t<T, U>>
    hankel_h_1(T n, U z) {
        using type = fp_promote_t<T, U>;

        return z;
    }
}

#endif // SPECIAL_FUNCTIONS_HANKEL_H_1_H
