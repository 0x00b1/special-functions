#ifndef SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H
#define SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    bernoulli_number(unsigned int n) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::bernoulli<type>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_BERNOULLI_NUMBER_H
