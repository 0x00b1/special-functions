#ifndef SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_H
#define SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_H

#include "bernoulli_number_by_series_summation.h"

namespace detail {
    template<typename T>
    constexpr T
    bernoulli_number(unsigned int n) {
        return bernoulli_number_by_series_summation<T>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_H
