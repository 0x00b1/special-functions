#ifndef SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_SIGN_H
#define SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_SIGN_H

namespace special_functions::detail {
/**
   * @brief Return the sign of the exponentiated logarithm
   * of the binomial coefficient for non-integral degree.
   * The binomial coefficient is given by:
   * @f[
   *   \binom{\nu}{k} = \frac{\Gamma(\nu+1)}{\Gamma(\nu-k+1) \Gamma(k+1)}
   * @f]
   * The binomial coefficients are generated by:
   * @f[
   *   \left(1 + t\right)^\nu = \sum_{k=0}^\infty \binom{\nu}{k} t^k
   * @f]
   *
   * @param nu The first argument of the binomial coefficient.
   * @param k The second argument of the binomial coefficient.
   * @return  The sign of the gamma function.
   */
  template<typename T>
    T
    log_binomial_sign(T nu, unsigned int k)
    {
      auto n = std::nearbyint(nu);
      if (n >= 0 && nu == n)
	return T{1};
      else
	{
	  return log_gamma_sign(T(1) + nu)
	       * log_gamma_sign(T(1 + k))
	       * log_gamma_sign(T(1 - k) + nu);
	}
    }

  template<typename T>
    std::complex<T>
    log_binomial_sign(std::complex<T> nu, unsigned int k)
    { return std::complex<T>{1}; }
}

#endif // SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_SIGN_H
