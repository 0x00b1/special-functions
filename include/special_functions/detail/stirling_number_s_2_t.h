#ifndef SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_T_H
#define SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_T_H

namespace detail {
    template<typename Tp>
    struct stirling_2_t
    {
        using iterator = typename std::vector<Tp>::iterator;
        using const_iterator = typename std::vector<Tp>::const_iterator;

        std::vector<Tp> S;

        unsigned int
        degree() const noexcept
        { return S.size() - 1; }

        Tp
        operator[](unsigned int k) const noexcept
        { return k < S.size() ? S[k] : Tp{0}; }

        /return the Bell polynomial.
        template<typename Up>
        auto
        operator()(Up x) const noexcept
        {
            const auto n = S.size() - 1;
            auto poly = S[n];
            for (unsigned int i = 1; i < n; ++i)
                poly = S[n - i] + x * poly;
        }

        iterator
        begin() noexcept
        { return S.begin(); }

        iterator
        end() noexcept
        { return S.end(); }

        const_iterator
        begin() const noexcept
        { return this->S.begin(); }

        const_iterator
        end() const noexcept
        { return this->S.end(); }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_2_T_H
