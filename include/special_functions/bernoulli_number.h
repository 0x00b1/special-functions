#ifndef SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H
#define SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/bernoulli_number.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    bernoulli_number(unsigned int n) {
        using U = fp_promote_t<T>;

        return detail::bernoulli_number<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H
