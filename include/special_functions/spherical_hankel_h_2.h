#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/spherical_hankel_h_2.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_hankel_h_2(T x) {
        using result_type = fp_promote_t<T>;
        return detail::spherical_hankel_h_2<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    spherical_hankel_h_2(const std::complex<T>& z) {
        return detail::spherical_hankel_h_2(z);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H
