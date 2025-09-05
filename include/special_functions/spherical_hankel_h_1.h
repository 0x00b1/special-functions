#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/spherical_hankel_h_1.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_hankel_h_1(T x) {
        using result_type = fp_promote_t<T>;
        return detail::spherical_hankel_h_1<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    spherical_hankel_h_1(const std::complex<T>& z) {
        return detail::spherical_hankel_h_1(z);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H
