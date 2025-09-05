#ifndef SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H
#define SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/harmonic_number.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    harmonic_number(T x) {
        using result_type = fp_promote_t<T>;
        return detail::harmonic_number<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H
