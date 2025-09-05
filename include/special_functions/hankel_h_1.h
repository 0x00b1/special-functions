#ifndef SPECIAL_FUNCTIONS_HANKEL_H_1_H
#define SPECIAL_FUNCTIONS_HANKEL_H_1_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/hankel_h_1.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    hankel_h_1(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::hankel_h_1<result_type>(x, y, z);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    hankel_h_1(const std::complex<T>& z) {
        return detail::hankel_h_1(z);
    }
}

#endif // SPECIAL_FUNCTIONS_HANKEL_H_1_H
