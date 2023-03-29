#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_G_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_G_H

namespace special_functions::detail {
    /**
 * @brief  Return the symmetric Carlson elliptic function of the second kind
 * 	     @f$ R_G(x,y,z) @f$.
 *
 * The Carlson symmetric elliptic function of the second kind is defined by:
 * @f[
 * 	 R_G(x,y,z) = \frac{1}{4} \int_0^\infty
 * 		   dt t [(t + x)(t + y)(t + z)]^{-1/2}
 * 		   (\frac{x}{t + x} + \frac{y}{t + y} + \frac{z}{t + z})
 * @f]
 *
 * Based on Carlson's algorithms:
 * -  B. C. Carlson Numer. Math. 33, 1 (1979)
 * -  B. C. Carlson, Special Functions of Applied Mathematics (1977)
 * -  Numerical Recipes in C, 2nd ed, pp. 261-269,
 * 	by Press, Teukolsky, Vetterling, Flannery (1992)
 *
 * @param  x  The first of three symmetric arguments.
 * @param  y  The second of three symmetric arguments.
 * @param  z  The third of three symmetric arguments.
 * @return  The Carlson symmetric elliptic function of the second kind.
 */

    template<typename Tp>
    Tp
    ellint_rg(Tp x, Tp y, Tp z)
    {
        using Real = emsr::num_traits_t<Tp>;
        const auto s_NaN = emsr::quiet_NaN(Real{});

        if (std::isnan(x) || std::isnan(y) || std::isnan(z))
            return s_NaN;
        else if (z == Tp{0})
            return comp_ellint_rg(x, y);
        else if (x == Tp{0})
            return comp_ellint_rg(y, z);
        else if (y == Tp{0})
            return comp_ellint_rg(z, x);
        else
            //return (z * ellint_rf(x, y, z)
            //     - (x - z) * (y - z) * ellint_rd(x, y, z) / Real{3}
            //     + (std::sqrt(x) * std::sqrt(y) / std::sqrt(z))) / Real{2};
            // There is a symmetric version that is less subject to cancellation loss
            // when the arguments are real:
            return (x * (y + z) * ellint_rd(y, z, x)
                    + y * (z + x) * ellint_rd(z, x, y)
                    + z * (x + y) * ellint_rd(x, y, z)) / Real{6};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_G_H
