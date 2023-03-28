#ifndef SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H
#define SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H

#include <special_functions/detail/bernoulli_number.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    bernoulli_number(unsigned int n) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::bernoulli_number<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H
