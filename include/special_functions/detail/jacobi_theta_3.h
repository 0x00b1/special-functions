#ifndef SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_3_H
#define SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_3_H

namespace detail {
    /**
 * Return the Jacobi @f$ \theta_3 @f$ function by summation of the series.
 *
 * The Jacobi or elliptic theta-3 function is defined by
 * @f[
 *  \theta_3(q,x) = 1 + 2\sum_{n=1}^{\infty} q^{n^2}\cos{2nx}
 * @f]
 *
 * @param q The elliptic nome, @f$ |q| < 1 @f$.
 * @param x The argument.
 */
    template<typename Tp>
    Tp
    jacobi_theta_3_sum(Tp q, Tp x) {
        using Real = num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        constexpr std::size_t s_max_iter = 50;

        Tp sum{};
        for (std::size_t n = 1; n < s_max_iter; ++n) {
            const auto term = std::pow(q, Real(n * n))
                              * std::cos(Real(2 * n) * x);
            sum += term;
            if (std::abs(term) < s_eps * std::abs(sum))
                break;
        }
        return Real{1} + Real{2} * sum;
    }

    /**
     * Return the Jacobi @f$ \theta_3 @f$ function by accumulation of the product.
     *
     * The Jacobi or elliptic theta-3 function is defined by
     * @f[
     *  \theta_3(q,x) = \prod_{n=1}^{\infty}
     *                   (1 - q^{2n})(1 + 2q^{2n-1}\cos(2x) + q^{4n-2})
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    Tp
    jacobi_theta_3_prod(Tp q, Tp x) {
        using Real = num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        constexpr std::size_t s_max_iter = 50;
        const auto q2 = q * q;
        const auto q4 = q2 * q2;
        const auto cos2x = std::cos(Real{2} * x);

        auto q2nm1 = q;
        auto q4nm2 = q2;
        auto prod = Tp{1};
        for (std::size_t n = 1; n < s_max_iter; ++n) {
            const auto fact = (Real{1} - q2nm1 * q)
                              * (Real{1} + Real{2} * q2nm1 * cos2x + q4nm2);
            prod *= fact;
            if (std::abs(fact) < s_eps)
                break;
            q2nm1 *= q2;
            q4nm2 *= q4;
        }

        return prod;
    }

    /**
     * Return the Jacobi @f$ \theta_3 @f$ function by summation of the series.
     *
     * The Jacobi or elliptic theta function is defined by
     * @f[
     *  \theta_3(q,x) = 1 + 2\sum_{n=1}^{\infty} q^{n^2}\cos{2nx}
     * @f]
     *
     * Regarding the nome and the theta function as functions of the lattice
     * parameter @f$ \tau -i log(q)/ \pi @f$ or @f$ q = e^{i\pi\tau} @f$
     * the lattice parameter is transformed to maximize its imaginary part:
     * @f[
     *   \theta_3(\tau+1,x) = \theta_3(\tau,x)
     * @f]
     * and
     * @f[
     *   \sqrt{-i\tau}\theta_3(\tau,x) = e^{(i\tau x^2/\pi)}\theta_3(\tau',\tau' x)
     * @f]
     * where the new lattice parameter is @f$ \tau' = -1/\tau @f$.
     *
     * The argument is reduced with
     * @f[
     *   \theta_3(q, x + (m+n\tau)\pi) = q^{-n^2} e^{-2inx} \theta_3(q, x)
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    std::complex<Tp>
    jacobi_theta_3(std::complex<Tp> q, std::complex<Tp> x) {
        using Real = num_traits_t<Tp>;
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
            throw std::domain_error("jacobi_theta_3: nome q out of range");
        else if (std::abs(q) < s_q_min || std::abs(q) > s_q_max)
            return jacobi_theta_3_prod(q, x);
        else if (std::abs(x) < s_eps)
#if cplusplus > 201403L
            return jacobi_theta_0_t(jacobi_lattice_t<Cmplx, Cmplx>(q)).th3;
#else
            return jacobi_theta_0_t<Cmplx, Cmplx>(
                    jacobi_lattice_t<Cmplx, Cmplx>(q)).th3;
#endif
        else {
            const auto lattice = jacobi_lattice_t<Cmplx, Cmplx>(q);
            auto tau = lattice.tau().val;

            const auto x_red = lattice.reduce(x);
            auto fact = std::complex<Tp>{1, 0};
            if (x_red.n != 0)
                fact *= std::exp(s_i * Real(-2 * x_red.n) * x_red.z)
                        * std::pow(q, -x_red.n * x_red.n);
            x = x_red.z;

            // theta_3(tau+1, z) = theta_3(tau, z)
            const auto itau = std::floor(std::real(tau));
            tau -= itau;

            if (std::imag(tau) < 0.5) {
                const auto fact2 = std::sqrt(-s_i * tau);
                tau = Real{-1} / tau;
                const auto phase = std::exp(s_i * tau * x * x / s_pi);
                fact *= phase / fact2;
                q = std::exp(s_i * s_pi * tau);
                x *= tau;
            }

            return fact * jacobi_theta_3_sum(q, x);
        }
    }

    /**
     * Return the Jacobi @f$ \theta_3 @f$ function for real nome and argument.
     *
     * The Jacobi or elliptic theta function is defined by
     * @f[
     *  \theta_3(q,x) = 1 + 2\sum_{n=1}^{\infty} q^{n^2}\cos{2nx}
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    Tp
    jacobi_theta_3(Tp q, const Tp x) {
        using Cmplx = std::complex<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();

        const auto ret = jacobi_theta_3(Cmplx(q), Cmplx(x));

        if (std::abs(ret) > s_eps
            && std::abs(std::imag(ret)) > s_eps * std::abs(ret))
            throw std::runtime_error("jacobi_theta_3: "
                                     "Unexpected large imaginary part");
        else
            return std::real(ret);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_3_H
