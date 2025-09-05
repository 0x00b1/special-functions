#ifndef SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_1_T_H
#define SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_1_T_H

namespace detail {
    template<typename Tp>
    struct stirling_1_t
    {
        using iterator = typename std::vector<Tp>::iterator;
        using const_iterator = typename std::vector<Tp>::const_iterator;

        std::vector<Tp> sigma;

        unsigned int
        degree() const noexcept
        { return sigma.size() - 1; }

        Tp
        operator[](unsigned int k) const noexcept
        { return k < sigma.size() ? sigma[k] : Tp{0}; }

        template<typename Up>
        auto
        operator()(Up x) const noexcept
        {
            const auto n = sigma.size() - 1;
            auto poly = sigma[n];
            for (unsigned int i = 1; i < n; ++i)
                poly = sigma[n - i] + x * poly;
        }

        iterator
        begin() noexcept
        { return sigma.begin(); }

        iterator
        end() noexcept
        { return sigma.end(); }

        const_iterator
        begin() const noexcept
        { return this->sigma.begin(); }

        const_iterator
        end() const noexcept
        { return this->sigma.end(); }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_STIRLING_NUMBER_S_1_T_H
