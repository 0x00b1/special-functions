#include <cmath>
#include <cstdint>

#include "sf_common.h"
#include "generated/log_gamma_float64.h"
#include "generated/log_gamma_float32.h"

namespace {

// x in [1, 3]: log|Gamma| has zeros at exactly 1 and 2; the generated fit
// approximates log_gamma(x) / ((x-1)(x-2)), so those zeros are exact.
double interval_f64(double x) {
    // Coefficients are a polynomial in t = x - 2 (centered basis; see Task 4).
    return (x - 1.0) * (x - 2.0)
        * polevl(x - SF_LOG_GAMMA_FLOAT64_INTERVAL_CENTER, SF_LOG_GAMMA_FLOAT64_INTERVAL, SF_LOG_GAMMA_FLOAT64_INTERVAL_N);
}

double positive_f64(double x) {
    if (x >= SF_LOG_GAMMA_FLOAT64_STIRLING_THRESHOLD) {
        double lx = std::log(x);
        double z = 1.0 / (x * x);
        double tail =
            polevl(z, SF_LOG_GAMMA_FLOAT64_STIRLING, SF_LOG_GAMMA_FLOAT64_STIRLING_N) / x;
        return (x - 0.5) * lx - x + SF_LOG_SQRT_TWO_PI + tail;
    }
    double acc = 0.0;
    double y = x;
    while (y >= 3.0) { y -= 1.0; acc += std::log(y); }   // lgam(y+1) = lgam(y) + log(y)
    while (y < 1.0)  { acc -= std::log(y); y += 1.0; }   // lgam(y) = lgam(y+1) - log(y)
    return interval_f64(y) + acc;
}

double log_gamma_scalar_f64(double x) {
    if (std::isnan(x)) return x;
    if (std::isinf(x)) return INFINITY;                  // log|Gamma| convention
    if (x <= 0.0 && x == std::floor(x)) return INFINITY; // poles incl. +/-0
    if (x < 0.0) {
        // |Gamma(x)| = pi / (|sin(pi x)| * |Gamma(1-x)|)
        return SF_LOG_PI - std::log(std::fabs(sf_sin_pi(x))) - positive_f64(1.0 - x);
    }
    return positive_f64(x);
}

float interval_f32(float x) {
    // Coefficients are a polynomial in t = x - 2 (centered basis; see Task 4).
    return (x - 1.0f) * (x - 2.0f)
        * polevlf(x - SF_LOG_GAMMA_FLOAT32_INTERVAL_CENTER, SF_LOG_GAMMA_FLOAT32_INTERVAL, SF_LOG_GAMMA_FLOAT32_INTERVAL_N);
}

float positive_f32(float x) {
    if (x >= SF_LOG_GAMMA_FLOAT32_STIRLING_THRESHOLD) {
        float lx = std::log(x);
        float z = 1.0f / (x * x);
        float tail =
            polevlf(z, SF_LOG_GAMMA_FLOAT32_STIRLING, SF_LOG_GAMMA_FLOAT32_STIRLING_N) / x;
        return (x - 0.5f) * lx - x + (float)SF_LOG_SQRT_TWO_PI + tail;
    }
    float acc = 0.0f;
    float y = x;
    while (y >= 3.0f) { y -= 1.0f; acc += std::log(y); }
    while (y < 1.0f)  { acc -= std::log(y); y += 1.0f; }
    return interval_f32(y) + acc;
}

float log_gamma_scalar_f32(float x) {
    if (std::isnan(x)) return x;
    if (std::isinf(x)) return INFINITY;
    if (x <= 0.0f && x == std::floor(x)) return INFINITY;
    if (x < 0.0f) {
        return (float)SF_LOG_PI - std::log(std::fabs(sf_sin_pi_f(x))) - positive_f32(1.0f - x);
    }
    return positive_f32(x);
}

}  // namespace

extern "C" void sf_cpu_log_gamma_float64(const double* x, double* out, int64_t n) {
    for (int64_t i = 0; i < n; ++i) out[i] = log_gamma_scalar_f64(x[i]);
}

extern "C" void sf_cpu_log_gamma_float32(const float* x, float* out, int64_t n) {
    for (int64_t i = 0; i < n; ++i) out[i] = log_gamma_scalar_f32(x[i]);
}
