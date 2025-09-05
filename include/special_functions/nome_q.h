#ifndef SPECIAL_FUNCTIONS_NOME_Q_H
#define SPECIAL_FUNCTIONS_NOME_Q_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/nome_q.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    nome_q(T x) {
        using result_type = fp_promote_t<T>;
        return detail::nome_q<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_NOME_Q_H
