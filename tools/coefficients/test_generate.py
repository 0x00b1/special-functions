import re
from pathlib import Path

import mpmath as mp
import numpy as np

from tools.coefficients.generate import (
    _dg_centered,
    _lg_centered,
    chebfit_auto,
    digamma_tail_coefficients,
    digamma_zero,
    digamma_zero_split,
    stirling_coefficients,
)

ROOT = Path(__file__).resolve().parents[2]


def _lg(x):
    # log_gamma(x) / ((x-1)(x-2)): removable 0/0 at x=1 and x=2 (log_gamma
    # vanishes at both). mpmath's chebyfit evaluates f exactly at these
    # points (the centered fit's interval midpoint t=0 is x=2; x=1 is the
    # left endpoint of the verification grid), and mpf division raises on
    # literal 0/0, so continue smoothly via L'Hopital:
    # limit = digamma(x) / (2x - 3), i.e. euler at x=1, 1 - euler at x=2.
    if x == 1:
        return -mp.digamma(1)
    if x == 2:
        return mp.digamma(2)
    return mp.log(abs(mp.gamma(x))) / ((x - 1) * (x - 2))


def _h(t):
    # Centered interval function: t = x - 2, t in [-1, 1].
    return _lg(t + 2)


def test_chebfit_auto_meets_target():
    # Validation must match what ships: coefficients cast to float64 and
    # evaluated with Horner in float64 arithmetic, compared to 60-dps truth.
    coeffs = chebfit_auto(_h, -1.0, 1.0, target_rel=4e-16)
    ts = np.linspace(-1.0, 1.0, 2001)
    worst = 0.0
    with mp.workdps(60):
        for t in ts:
            tt = np.float64(t)
            acc = np.float64(0.0)
            for c in coeffs:
                acc = acc * tt + np.float64(c)
            true = _h(mp.mpf(float(tt)))
            worst = max(worst, abs(float((mp.mpf(float(acc)) - true) / true)))
    assert worst <= 4e-16


def test_stirling_truncation_bound_at_threshold():
    coeffs = stirling_coefficients(threshold=13.0, target_rel=2.0**-54)
    # Next-term bound must already have been asserted inside; sanity: first
    # coefficient is B_2/(2*1) = 1/12.
    assert abs(coeffs[-1] - 1.0 / 12.0) < 1e-16


def test_digamma_tail_first_coefficient():
    coeffs = digamma_tail_coefficients(threshold=10.0, target_rel=2.0**-54)
    # B_2/2 = 1/12.
    assert abs(coeffs[-1] - 1.0 / 12.0) < 1e-16


def test_chebfit_auto_float32_path():
    """Test float32-specific INTERVAL fit as used in main() for log_gamma."""
    coeffs = chebfit_auto(_lg_centered, -1.0, 1.0, target_rel=2.4e-7, dtype=np.float32)
    assert coeffs is not None

    # Coefficients must survive float32 round-trip and be finite
    for c in coeffs:
        c_f32 = np.float32(c)
        assert np.isfinite(c_f32), f"coefficient {c} is not finite after float32 cast"
        # Round-trip: cast to float32 and back should match the float32 value
        c_roundtrip = np.float32(np.float64(c_f32))
        assert c_f32 == c_roundtrip, f"coefficient {c} does not survive float32 round-trip"

    # Evaluate with Horner in float32 against 60-dps truth
    ts = np.linspace(-1.0, 1.0, 501)
    worst = 0.0
    with mp.workdps(60):
        for t in ts:
            tt = np.float32(t)
            acc = np.float32(0.0)
            for c in coeffs:
                c_f32 = np.float32(c)
                acc = acc * tt + c_f32
            true = _lg_centered(mp.mpf(float(tt)))
            rel_err = abs(float((mp.mpf(float(acc)) - true) / true))
            worst = max(worst, rel_err)
    assert worst <= 2.4e-7, f"worst relative error {worst} exceeds target 2.4e-7"


def test_digamma_zero_is_psi_root():
    x0 = digamma_zero()
    with mp.workdps(60):
        assert abs(mp.digamma(x0)) < mp.mpf("1e-55")
        # Known value: 1.46163214496836234126...
        assert abs(x0 - mp.mpf("1.46163214496836234126")) < mp.mpf("1e-20")


def test_digamma_zero_split_exact_roundings():
    """hi must be the target-precision rounding of x0 and lo the
    target-precision rounding of the residual x0 - hi; the remaining error
    |hi + lo - x0| is then bounded by the rounding of lo (~eps * |lo|)."""
    x0 = digamma_zero()
    with mp.workdps(60):
        for np_dtype, eps in ((np.float64, 2.0**-52), (np.float32, 2.0**-23)):
            hi, lo = digamma_zero_split(np_dtype)
            assert hi == np_dtype(float(x0))
            assert lo == np_dtype(float(x0 - mp.mpf(float(hi))))
            resid = abs(x0 - (mp.mpf(float(hi)) + mp.mpf(float(lo))))
            assert resid <= eps * abs(mp.mpf(float(lo)))
            # (x - hi) - lo must reproduce the true distance to the zero to
            # ~1 ulp of the distance for x near the zero.
            x = np_dtype(1.462)
            d_true = mp.mpf(float(x)) - x0
            d_c = (x - hi) - lo  # same expression the C code evaluates
            assert abs(mp.mpf(float(d_c)) - d_true) <= 2 * eps * abs(d_true)


def test_digamma_interval_meets_target():
    # Validation must match what ships: coefficients cast to float64 and
    # evaluated with Horner in float64 arithmetic, compared to 60-dps truth.
    coeffs = chebfit_auto(_dg_centered, -0.5, 0.5, target_rel=4e-16)
    ts = np.linspace(-0.5, 0.5, 2001)
    worst = 0.0
    with mp.workdps(60):
        for t in ts:
            tt = np.float64(t)
            acc = np.float64(0.0)
            for c in coeffs:
                acc = acc * tt + np.float64(c)
            true = _dg_centered(mp.mpf(float(tt)))
            worst = max(worst, abs(float((mp.mpf(float(acc)) - true) / true)))
    assert worst <= 4e-16


def test_digamma_interval_float32_path():
    """Test float32-specific INTERVAL fit as used in main() for digamma."""
    coeffs = chebfit_auto(_dg_centered, -0.5, 0.5, target_rel=2.4e-7, dtype=np.float32)
    assert coeffs is not None

    # Coefficients must survive float32 round-trip and be finite
    for c in coeffs:
        c_f32 = np.float32(c)
        assert np.isfinite(c_f32), f"coefficient {c} is not finite after float32 cast"
        c_roundtrip = np.float32(np.float64(c_f32))
        assert c_f32 == c_roundtrip, f"coefficient {c} does not survive float32 round-trip"

    # Evaluate with Horner in float32 against 60-dps truth
    ts = np.linspace(-0.5, 0.5, 501)
    worst = 0.0
    with mp.workdps(60):
        for t in ts:
            tt = np.float32(t)
            acc = np.float32(0.0)
            for c in coeffs:
                acc = acc * tt + np.float32(c)
            true = _dg_centered(mp.mpf(float(tt)))
            rel_err = abs(float((mp.mpf(float(acc)) - true) / true))
            worst = max(worst, rel_err)
    assert worst <= 2.4e-7, f"worst relative error {worst} exceeds target 2.4e-7"


def _parse_header_define(header_path: Path, define_name: str) -> int:
    """Parse a #define N value from a generated header file."""
    content = header_path.read_text()
    pattern = rf"#define {re.escape(define_name)} (\d+)"
    match = re.search(pattern, content)
    if not match:
        raise ValueError(f"Could not find {define_name} in {header_path}")
    return int(match.group(1))


def _parse_header_scalar(header_path: Path, define_name: str) -> float:
    """Parse a floating-point #define value from a generated header file."""
    content = header_path.read_text()
    pattern = rf"#define {re.escape(define_name)} ([0-9.eE+-]+?)f?\n"
    match = re.search(pattern, content)
    if not match:
        raise ValueError(f"Could not find {define_name} in {header_path}")
    return float(match.group(1))


def test_digamma_zero_split_header_roundtrip():
    """The emitted ZERO_HI/ZERO_LO literals must parse back to the exact
    target-precision split values."""
    gen_dir = ROOT / "special_functions_cpu" / "generated"
    for dt, np_dtype in (("float64", np.float64), ("float32", np.float32)):
        hi, lo = digamma_zero_split(np_dtype)
        header = gen_dir / f"digamma_{dt}.h"
        prefix = f"SF_DIGAMMA_{dt.upper()}"
        assert np_dtype(_parse_header_scalar(header, f"{prefix}_ZERO_HI")) == hi
        assert np_dtype(_parse_header_scalar(header, f"{prefix}_ZERO_LO")) == lo


def test_series_float32_thresholds():
    """Test float32-specific series generators at thresholds used in main()."""
    # Call the exact float32 configurations from main()
    stirling_coeffs = stirling_coefficients(threshold=8.0, target_rel=2.0**-27)
    digamma_coeffs = digamma_tail_coefficients(threshold=6.0, target_rel=2.0**-27)

    # Both series must have their first coefficient (last in reversed list) as 1/12
    assert abs(stirling_coeffs[-1] - 1.0 / 12.0) < 1e-16, \
        f"stirling last coeff {stirling_coeffs[-1]} not close to 1/12"
    assert abs(digamma_coeffs[-1] - 1.0 / 12.0) < 1e-16, \
        f"digamma last coeff {digamma_coeffs[-1]} not close to 1/12"

    # Parse expected lengths from the checked-in float32 headers
    lg_header = ROOT / "special_functions_cpu" / "generated" / "log_gamma_float32.h"
    dg_header = ROOT / "special_functions_cpu" / "generated" / "digamma_float32.h"

    expected_stirling_n = _parse_header_define(lg_header, "SF_LOG_GAMMA_FLOAT32_STIRLING_N")
    expected_digamma_n = _parse_header_define(dg_header, "SF_DIGAMMA_FLOAT32_TAIL_N")

    assert len(stirling_coeffs) == expected_stirling_n, \
        f"stirling coefficients length {len(stirling_coeffs)} != expected {expected_stirling_n}"
    assert len(digamma_coeffs) == expected_digamma_n, \
        f"digamma coefficients length {len(digamma_coeffs)} != expected {expected_digamma_n}"
