#ifndef SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_2_H
#define SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_2_H

namespace special_functions::detail {
    /**
 * Return the Jacobi @f$ \theta_2 @f$ function by summation of the series.
 *
 * The Jacobi or elliptic theta-2 function is defined by
 * @f[
 *  \theta_2(q,x) = 2\sum_{n=1}^{\infty}
 *                   q^{(n+\frac{1}{2})^2}\cos{(2n+1)x}
 * @f]
 *
 * @param q The elliptic nome, @f$ |q| < 1 @f$.
 * @param x The argument.
 */
    template<typename Tp>
    Tp
    jacobi_theta_2_sum(Tp q, Tp x)
    {
        using Real = special_functions::num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        constexpr std::size_t s_max_iter = 50;

        Tp sum{};
        for (std::size_t n = 0; n < s_max_iter; ++n)
        {
            const auto term = std::pow(q, Real((n + 0.5L) * (n + 0.5L)))
                              * std::cos(Real(2 * n + 1) * x);
            sum += term;
            if (std::abs(term) < s_eps * std::abs(sum))
                break;
        }
        return Real{2} * sum;
    }

    /**
     * Return the Jacobi @f$ \theta_2 @f$ function by accumulation of the product.
     *
     * The Jacobi or elliptic theta-2 function is defined by
     * @f[
     *  \theta_2(q,x) = 2 q^{1/4} \sin(x) \prod_{n=1}^{\infty}
     *                   (1 - q^{2n})(1 + 2q^{2n}\cos(2x) + q^{4n})
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    Tp
    jacobi_theta_2_prod(Tp q, Tp x)
    {
        using Real = special_functions::num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        constexpr std::size_t s_max_iter = 50;
        const auto q2 = q * q;
        const auto q4 = q2 * q2;
        const auto cos2x = std::cos(Real{2} * x);

        auto q2n = Tp{1};
        auto q4n = Tp{1};
        auto prod = Tp{1};
        for (std::size_t n = 1; n < s_max_iter; ++n)
        {
            q2n *= q2;
            q4n *= q4;
            const auto fact = (Real{1} - q2n)
                              * (Real{1} + Real{2} * q2n * cos2x + q4n);
            prod *= fact;
            if (std::abs(fact) < s_eps)
                break;
        }

        return Real{2} * std::pow(q, Tp{0.25L}) * std::cos(x) * prod;
    }

    // Pre-declare Jacobi theta_4 sum ...
    template<typename Tp>
    Tp
    jacobi_theta_4_sum(Tp q, Tp x);

    // ... and product.
    template<typename Tp>
    Tp
    jacobi_theta_4_prod(Tp q, Tp x);

    /**
     * Return the Jacobi @f$ \theta_2 @f$ function by summation of the series.
     *
     * The Jacobi or elliptic theta function is defined by
     * @f[
     *  \theta_2(q,x) = 2\sum_{n=1}^{\infty}
     *                   q^{(n+\frac{1}{2})^2}\cos{(2n+1)x}
     * @f]
     *
     * Regarding the nome and the theta function as functions of the lattice
     * parameter @f$ \tau -i log(q)/ \pi @f$ or @f$ q = e^{i\pi\tau} @f$
     * the lattice parameter is transformed to maximize its imaginary part:
     * @f[
     *   \theta_2(\tau+1,x) = e^{i\pi/4}\theta_2(\tau,x)
     * @f]
     * and
     * @f[
     *   \sqrt{-i\tau}\theta_2(\tau,x) = e^{(i\tau x^2/\pi)}\theta_4(\tau',\tau' x)
     * @f]
     * where the new lattice parameter is @f$ \tau' = -1/\tau @f$.
     *
     * The argument is reduced with
     * @f[
     *  \theta_2(q, x + (m+n\tau)\pi) = (-1)^{m}q^{-n^2}e^{-2inx}\theta_2(q, x)
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    std::complex<Tp>
    jacobi_theta_2(std::complex<Tp> q, std::complex<Tp> x)
    {
        using Real = special_functions::num_traits_t<Tp>;
        using Cmplx = std::complex<Real>;
        const auto s_NaN = std::numeric_limits<Tp>::quiet_NaN();
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        const auto s_pi = std::numbers::pi_v<Real>;
        const auto s_i = std::complex<Real>{0, 1};
        constexpr auto s_q_min = Real{0.001L};
        constexpr auto s_q_max = Real{0.95e-1L};

        if (std::isnan(q) || std::isnan(x))
            return Tp{s_NaN};
        else if (std::abs(q) >= Real{1})
            throw std::domain_error("jacobi_theta_2: nome q out of range");
        else if (std::abs(q) < s_q_min || std::abs(q) > s_q_max)
            return jacobi_theta_2_prod(q, x);
        else if (std::abs(x) < s_eps)
#if cplusplus > 201403
            return jacobi_theta_0_t(jacobi_lattice_t<Cmplx, Cmplx>(q)).th2;
#else
            return jacobi_theta_0_t<Cmplx, Cmplx>(
                    jacobi_lattice_t<Cmplx, Cmplx>(q)).th2;
#endif
        else
        {
            const auto lattice = jacobi_lattice_t<Cmplx, Cmplx>(q);
            auto tau = lattice.tau().val;

            const auto x_red = lattice.reduce(x);
            auto fact = std::complex<Tp>{1, 0};
            if (x_red.m != 0)
                fact *= special_functions::parity<Tp>(x_red.m);
            if (x_red.n != 0)
                fact *= std::exp(s_i * Real(-2 * x_red.n) * x_red.z)
                        * std::pow(q, -x_red.n * x_red.n);
            x = x_red.z;

            // theta_2(tau+1, z) = theta_2(tau, z)
            const auto itau = std::floor(std::real(tau));
            tau -= itau;
            fact *= polar_pi(Real{1}, itau / Real{4});

            if (std::imag(tau) < 0.5)
            {
                const auto fact2 = std::sqrt(-s_i * tau);
                tau = Real{-1} / tau;
                const auto phase = std::exp(s_i * tau * x * x / s_pi);
                fact *= phase / fact2;
                q = std::exp(s_i * s_pi * tau);
                x *= tau;
                return fact * jacobi_theta_4_sum(q, x);
            }
            else
                return fact * jacobi_theta_2_sum(q, x);
        }
    }

    /**
     * Return the Jacobi @f$ \theta_2 @f$ function for real nome and argument.
     *
     * The Jacobi or elliptic theta function is defined by
     * @f[
     *  \theta_2(q,x) = 2\sum_{n=1}^{\infty}
     *                   q^{(n+\frac{1}{2})^2}\cos{(2n+1)x}
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    Tp
    jacobi_theta_2(Tp q, const Tp x)
    {
        using Cmplx = std::complex<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();

        const auto ret = jacobi_theta_2(Cmplx(q), Cmplx(x));

        if (std::abs(ret) > s_eps
            && std::abs(std::imag(ret)) > s_eps * std::abs(ret))
            throw std::runtime_error("jacobi_theta_2: "
                                     "Unexpected large imaginary part");
        else
            return std::real(ret);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_2_H
