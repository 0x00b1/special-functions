#ifndef SPECIAL_FUNCTIONS_NOME_Q_H
#define SPECIAL_FUNCTIONS_NOME_Q_H

namespace special_functions {
    template<typename Tp>
    inline Tp
    ellnome(Tp k)
    {
        using type = special_functions::fp_promote_t<Tp>;
        return special_functions::detail::ellnome<type>(k);
    }
}

#endif // SPECIAL_FUNCTIONS_NOME_Q_H
