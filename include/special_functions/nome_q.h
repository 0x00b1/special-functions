#ifndef SPECIAL_FUNCTIONS_NOME_Q_H
#define SPECIAL_FUNCTIONS_NOME_Q_H

#include <special_functions/detail/nome_q.h>

namespace special_functions {
    template<typename T>
    inline T
    nome_q(T k) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::nome_q<U>(k);
    }
}

#endif // SPECIAL_FUNCTIONS_NOME_Q_H
