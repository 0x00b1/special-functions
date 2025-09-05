#ifndef SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_1_H
#define SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_1_H

namespace detail {
    /**
 * Return the Jacobi @f$ \theta_1 @f$ function by summation of the series.
 *
 * The Jacobi or elliptic theta-1 function is defined by
 * @f[
 *  \theta_1(q,x) = 2\sum_{n=1}^{\infty}(-1)^n
 *                   q^{(n+\frac{1}{2})^2}\sin{(2n+1)x}
 * @f]
 *
 * @param q The elliptic nome, @f$ |q| < 1 @f$.
 * @param x The argument.
 */
    template<typename Tp>
    Tp
    jacobi_theta_1_sum(Tp q, Tp x) {
        using Real = num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        constexpr std::size_t s_max_iter = 50;

        Tp sum{};
        Real sign{-1};
        for (std::size_t n = 0; n < s_max_iter; ++n) {
            sign *= -1;
            const auto term = sign
                              * std::pow(q, Real((n + 0.5L) * (n + 0.5L)))
                              * std::sin(Real(2 * n + 1) * x);
            sum += term;
            if (std::abs(term) < s_eps * std::abs(sum))
                break;
        }
        return Real{2} * sum;
    }

    /**
     * Return the Jacobi @f$ \theta_1 @f$ function by accumulation of the product.
     *
     * The Jacobi or elliptic theta-1 function is defined by
     * @f[
     *  \theta_1(q,x) = 2 q^{1/4} \sin(x) \prod_{n=1}^{\infty}
     *                   (1 - q^{2n})(1 - 2q^{2n}\cos(2x) + q^{4n})
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    Tp
    jacobi_theta_1_prod(Tp q, Tp x) {
        using Real = num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        constexpr std::size_t s_max_iter = 50;
        const auto q2 = q * q;
        const auto q4 = q2 * q2;
        const auto cos2x = std::cos(Real{2} * x);

        auto q2n = Tp{1};
        auto q4n = Tp{1};
        auto prod = Tp{1};
        for (std::size_t n = 1; n < s_max_iter; ++n) {
            q2n *= q2;
            q4n *= q4;
            const auto fact = (Real{1} - q2n)
                              * (Real{1} - Real{2} * q2n * cos2x + q4n);
            prod *= fact;
            if (std::abs(fact) < s_eps)
                break;
        }

        return Real{2} * std::pow(q, Tp{0.25L}) * std::sin(x) * prod;
    }

    /**
     * Return the Jacobi @f$ \theta_1 @f$ function by summation of the series.
     *
     * The Jacobi or elliptic theta function is defined by
     * @f[
     *  \theta_1(q,x) = 2\sum_{n=1}^{\infty}(-1)^n
     *                   q^{(n+\frac{1}{2})^2}\sin{(2n+1)x}
     * @f]
     *
     * Regarding the nome and the theta function as functions of the lattice
     * parameter @f$ \tau -i log(q)/ \pi @f$ or @f$ q = e^{i\pi\tau} @f$
     * the lattice parameter is transformed to maximize its imaginary part:
     * @f[
     *   \theta_1(\tau+1,x) = -i e^{i\pi/4}\theta_1(\tau,x)
     * @f]
     * and
     * @f[
     *   \sqrt{-i\tau}\theta_1(\tau,x) = e^{(i\tau x^2/\pi)}\theta_1(\tau',\tau' x)
     * @f]
     * where the new lattice parameter is @f$ \tau' = -1/\tau @f$.
     *
     * The argument is reduced with
     * @f[
     *   \theta_1(q, x+(m+n\tau)\pi) = (-1)^{m+n}q^{-n^2}e^{-2inx}\theta_1(q, x)
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    std::complex<Tp>
    jacobi_theta_1(std::complex<Tp> q, std::complex<Tp> x) {
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
            throw std::domain_error("jacobi_theta_1: nome q out of range");
        else if (std::abs(q) < s_q_min || std::abs(q) > s_q_max)
            return jacobi_theta_1_prod(q, x);
        else if (std::abs(x) < s_eps)
            return std::complex<Tp>{0, 0};
        else {
            const auto lattice = jacobi_lattice_t<Cmplx, Cmplx>(q);
            auto tau = lattice.tau().val;

            const auto x_red = lattice.reduce(x);
            auto fact = std::complex<Tp>{1, 0};
            if (x_red.m != 0)
                fact *= parity<Tp>(x_red.m);
            if (x_red.n != 0)
                fact *= parity<Tp>(x_red.n)
                        * std::exp(s_i * Real(-2 * x_red.n) * x_red.z)
                        * std::pow(q, -x_red.n * x_red.n);
            x = x_red.z;

            // theta_1(tau+1, z) = exp(i tau/4) theta_1(tau, z)
            const auto itau = std::floor(std::real(tau));
            tau -= itau;
            fact *= polar_pi(Real{1}, itau / Real{4});

            if (std::imag(tau) < 0.5) {
                const auto fact2 = s_i * std::sqrt(-s_i * tau);
                tau = Real{-1} / tau;
                const auto phase = std::exp(s_i * tau * x * x / s_pi);
                fact *= phase / fact2;
                q = std::exp(s_i * s_pi * tau);
                x *= tau;
            }

            return fact * jacobi_theta_1_sum(q, x);
        }
    }

    /**
     * Return the Jacobi @f$ \theta_1 @f$ function for real nome and argument.
     *
     * The Jacobi or elliptic theta function is defined by
     * @f[
     *  \theta_1(q,x) = 2\sum_{n=1}^{\infty}(-1)^n
     *                   q^{(n+\frac{1}{2})^2}\sin{(2n+1)x}
     * @f]
     *
     * @param q The elliptic nome, @f$ |q| < 1 @f$.
     * @param x The argument.
     */
    template<typename Tp>
    Tp
    jacobi_theta_1(Tp q, const Tp x) {
        using Cmplx = std::complex<Tp>;

        const auto s_eps = std::numeric_limits<Tp>::epsilon(std::abs(x));
        const auto ret = jacobi_theta_1(Cmplx(q), Cmplx(x));

        if (std::abs(ret) > s_eps
            && std::abs(std::imag(ret)) > s_eps * std::abs(ret))
            throw std::runtime_error("jacobi_theta_1: "
                                     "Unexpected large imaginary part");
        else
            return std::real(ret);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_JACOBI_THETA_1_H
