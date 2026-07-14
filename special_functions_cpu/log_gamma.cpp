#include <cmath>
#include <cstdint>

#include "sf_common.h"
#include "generated/log_gamma_float64.h"
#include "generated/log_gamma_float32.h"

extern "C" void sf_cpu_log_gamma_float64(const double* x, double* out, int64_t n) {
    for (int64_t i = 0; i < n; ++i) out[i] = NAN;
}

extern "C" void sf_cpu_log_gamma_float32(const float* x, float* out, int64_t n) {
    for (int64_t i = 0; i < n; ++i) out[i] = NAN;
}
