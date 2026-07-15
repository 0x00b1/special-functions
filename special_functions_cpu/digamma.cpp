#include <cmath>
#include <cstdint>

#include "sf_common.h"
#include "generated/digamma_float64.h"
#include "generated/digamma_float32.h"

namespace {

// x in [1, 2]: the generated fit approximates digamma(x) / (x - x0), where
// x0 ~ 1.4616321 is psi's positive zero, so that zero is exact in relative
// terms. x0 is not representable; the root distance is computed against the
// split x0 = ZERO_HI + ZERO_LO ((x - hi) - lo keeps the subtraction exact).
double interval_f64(double x) {
    // Coefficients are a polynomial in t = x - 1.5 (centered basis; Task 4).
    return ((x - SF_DIGAMMA_FLOAT64_ZERO_HI) - SF_DIGAMMA_FLOAT64_ZERO_LO)
        * polevl(x - SF_DIGAMMA_FLOAT64_INTERVAL_CENTER, SF_DIGAMMA_FLOAT64_INTERVAL, SF_DIGAMMA_FLOAT64_INTERVAL_N);
}

double positive_f64(double x) {
    if (x >= SF_DIGAMMA_FLOAT64_TAIL_THRESHOLD) {
        // psi(x) ~ ln x - 1/(2x) - z*P(z), z = 1/x^2.
        double z = 1.0 / (x * x);
        return std::log(x) - 0.5 / x
            - z * polevl(z, SF_DIGAMMA_FLOAT64_TAIL, SF_DIGAMMA_FLOAT64_TAIL_N);
    }
    if (x < 1.0) return interval_f64(x + 1.0) - 1.0 / x;  // psi(x) = psi(x+1) - 1/x
    double acc = 0.0;
    double y = x;
    while (y > 2.0) { y -= 1.0; acc += 1.0 / y; }  // psi(y+1) = psi(y) + 1/y
    return interval_f64(y) + acc;                  // all-positive accumulation
}

double digamma_scalar_f64(double x) {
    if (std::isnan(x)) return x;
    if (x == INFINITY) return INFINITY;
    if (x == -INFINITY) return NAN;
    if (x == 0.0) return std::signbit(x) ? INFINITY : -INFINITY; // psi ~ -1/x
    if (x < 0.0) {
        if (x == std::floor(x)) return NAN;                      // negative poles
        // DLMF 5.5.4: psi(1-x) = psi(x) + pi*cot(pi*x)
        return positive_f64(1.0 - x) - SF_PI * sf_cot_pi(x);
    }
    return positive_f64(x);
}

float interval_f32(float x) {
    // Coefficients are a polynomial in t = x - 1.5 (centered basis; Task 4).
    return ((x - SF_DIGAMMA_FLOAT32_ZERO_HI) - SF_DIGAMMA_FLOAT32_ZERO_LO)
        * polevlf(x - SF_DIGAMMA_FLOAT32_INTERVAL_CENTER, SF_DIGAMMA_FLOAT32_INTERVAL, SF_DIGAMMA_FLOAT32_INTERVAL_N);
}

float positive_f32(float x) {
    if (x >= SF_DIGAMMA_FLOAT32_TAIL_THRESHOLD) {
        float z = 1.0f / (x * x);
        return std::log(x) - 0.5f / x
            - z * polevlf(z, SF_DIGAMMA_FLOAT32_TAIL, SF_DIGAMMA_FLOAT32_TAIL_N);
    }
    if (x < 1.0f) return interval_f32(x + 1.0f) - 1.0f / x;
    float acc = 0.0f;
    float y = x;
    while (y > 2.0f) { y -= 1.0f; acc += 1.0f / y; }
    return interval_f32(y) + acc;
}

float digamma_scalar_f32(float x) {
    if (std::isnan(x)) return x;
    if (x == INFINITY) return INFINITY;
    if (x == -INFINITY) return NAN;
    if (x == 0.0f) return std::signbit(x) ? INFINITY : -INFINITY;
    if (x < 0.0f) {
        if (x == std::floor(x)) return NAN;
        return positive_f32(1.0f - x) - (float)SF_PI * sf_cot_pi_f(x);
    }
    return positive_f32(x);
}

}  // namespace

extern "C" void sf_cpu_digamma_float64(const double* x, double* out, int64_t n) {
    for (int64_t i = 0; i < n; ++i) out[i] = digamma_scalar_f64(x[i]);
}

extern "C" void sf_cpu_digamma_float32(const float* x, float* out, int64_t n) {
    for (int64_t i = 0; i < n; ++i) out[i] = digamma_scalar_f32(x[i]);
}
