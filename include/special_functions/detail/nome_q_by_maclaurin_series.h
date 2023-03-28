#ifndef SPECIAL_FUNCTIONS_DETAIL_NOME_Q_BY_MACLAURIN_SERIES_H
#define SPECIAL_FUNCTIONS_DETAIL_NOME_Q_BY_MACLAURIN_SERIES_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    nome_q_by_maclaurin_series(Tp k) {
        const auto m = k * k;
        return m * ((Tp{1} / Tp{16}) + m * ((Tp{1} / Tp{32}) + m * ((Tp{21} / Tp{1024}) + m * ((Tp{31} / Tp{2048}) + m *
                                                                                                                     (Tp{6257} /
                                                                                                                      Tp{524288})))));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_NOME_Q_BY_MACLAURIN_SERIES_H
