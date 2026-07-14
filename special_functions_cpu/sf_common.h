#pragma once

#include <cmath>
#include <cstdint>

// log(pi), log(sqrt(2*pi)) to full double precision.
#define SF_LOG_PI 1.1447298858494001741
#define SF_LOG_SQRT_TWO_PI 0.91893853320467274178

// Evaluate polynomial with coefficients highest-degree-first (Horner).
static inline double polevl(double x, const double* c, int n) {
    double r = c[0];
    for (int i = 1; i < n; ++i) r = r * x + c[i];
    return r;
}

static inline float polevlf(float x, const float* c, int n) {
    float r = c[0];
    for (int i = 1; i < n; ++i) r = r * x + c[i];
    return r;
}

// sin(pi*x) / cot(pi*x) with argument reduction done in exact float
// arithmetic (x - round(x) is exact), so accuracy is limited only by the
// final sin/cos call. Callers guarantee x is finite and non-integer.
static inline double sf_sin_pi(double x) {
    double r = x - std::nearbyint(x);          // r in [-0.5, 0.5], exact
    double s = std::sin(3.14159265358979323846 * r);
    long long n = (long long)std::nearbyint(x);
    return (n & 1) ? -s : s;
}

static inline double sf_cot_pi(double x) {
    double r = x - std::nearbyint(x);
    double p = 3.14159265358979323846 * r;
    return std::cos(p) / std::sin(p);          // periodic with period 1
}

static inline float sf_sin_pi_f(float x) {
    float r = x - std::nearbyint(x);
    float s = std::sin(3.14159265358979323846 * (double)r);
    long long n = (long long)std::nearbyint((double)x);
    return (n & 1) ? -s : s;
}

static inline float sf_cot_pi_f(float x) {
    double p = 3.14159265358979323846 * (double)(x - std::nearbyint(x));
    return (float)(std::cos(p) / std::sin(p));
}
