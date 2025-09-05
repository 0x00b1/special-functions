#ifndef SPECIAL_FUNCTIONS_NOME_Q_H
#define SPECIAL_FUNCTIONS_NOME_Q_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/nome_q.h>

namespace special_functions {
    template<typename T>
    T
    nome_q(T k) {
        using U = fp_promote_t<T>;

        return k;
    }
}

#endif // SPECIAL_FUNCTIONS_NOME_Q_H
