"""Generate mpmath ground-truth tables for the accuracy contract.

Truth is computed at 60 significant digits and correctly rounded to the
target dtype by exact rational round-to-nearest-even: the mpf's
sign/mantissa/exponent triple is converted to an exact `Fraction`, compared
against the exact `Fraction` values of the target dtype's nearest
candidates, and the true nearest (ties broken to even mantissa) is
selected. This avoids the double-rounding error a decimal-string
round-trip (str -> float64 -> float32) can introduce near float32 tie
midpoints. Tables are written to tests/references/<fn>_<dtype>.npz and
checked in. Poles and special values get closed-form expecteds per the
spec's edge-behavior contract.
"""

from fractions import Fraction
from pathlib import Path

import mpmath as mp
import numpy as np

ROOT = Path(__file__).resolve().parents[2]
OUT_DIR = ROOT / "tests" / "references"
SEED = 20260713
DPS = 60

# Round-to-nearest overflow threshold: max-representable-finite + half its ULP.
# Exact values at or beyond this magnitude round to infinity.
_OVERFLOW_THRESHOLD = {
    np.dtype(np.float32): Fraction(2) ** 128 - Fraction(2) ** 103,
    np.dtype(np.float64): Fraction(2) ** 1024 - Fraction(2) ** 970,
}

_UINT_VIEW = {
    np.dtype(np.float32): np.uint32,
    np.dtype(np.float64): np.uint64,
}


def _round_to(value: mp.mpf, dtype) -> float:
    """Round an mpmath value to `dtype` with exact round-to-nearest-even.

    Builds the exact rational value of the mpf, compares it against the
    exact rational values of the candidate float64/float32 result and its
    two immediate neighbors, and returns whichever candidate is truly
    closest -- breaking exact ties toward the candidate with an even
    mantissa. This is immune to the double-rounding error that a
    str -> float64 -> float32 conversion path can introduce.
    """
    np_dtype = np.dtype(dtype)
    sign, man, exp, _ = mp.mpf(value)._mpf_
    if man == 0:
        return dtype(0.0)

    exact = Fraction(man, 1) * Fraction(2) ** exp
    if sign:
        exact = -exact

    overflow = _OVERFLOW_THRESHOLD[np_dtype]
    if abs(exact) >= overflow:
        return dtype(np.inf) if exact > 0 else dtype(-np.inf)

    fi = np.finfo(np_dtype)
    approx = float(value)
    if not np.isfinite(approx):
        cand = dtype(fi.max) if approx > 0 else dtype(-fi.max)
    else:
        cand = dtype(approx)
        if not np.isfinite(cand):
            cand = dtype(fi.max) if cand > 0 else dtype(-fi.max)

    neighbors = [
        cand,
        np.nextafter(cand, dtype(np.inf), dtype=np_dtype),
        np.nextafter(cand, dtype(-np.inf), dtype=np_dtype),
    ]
    candidates = [c for c in neighbors if np.isfinite(c)]

    uint_dtype = _UINT_VIEW[np_dtype]

    def is_even(c) -> bool:
        return int(np.array(c, dtype=np_dtype).view(uint_dtype)) & 1 == 0

    best = None
    best_dist = None
    for c in candidates:
        dist = abs(exact - Fraction(float(c)))
        if best_dist is None or dist < best_dist:
            best, best_dist = c, dist
        elif dist == best_dist and is_even(c) and not is_even(best):
            best = c
    return dtype(best)


def _log_gamma_real(x: mp.mpf) -> mp.mpf:
    return mp.log(abs(mp.gamma(x)))


def _digamma_real(x: mp.mpf) -> mp.mpf:
    return mp.digamma(x)


def _log_gamma_special(x: float) -> float | None:
    if np.isnan(x):
        return np.nan
    if np.isinf(x):
        return np.inf  # log|gamma| -> +inf at both infinities
    if x <= 0.0 and float(x) == int(x):
        return np.inf  # poles, including +/-0
    return None


def _digamma_special(x: float) -> float | None:
    if np.isnan(x):
        return np.nan
    if np.isposinf(x):
        return np.inf
    if np.isneginf(x):
        return np.nan
    if x == 0.0:
        return np.inf if np.signbit(x) else -np.inf
    if x < 0.0 and float(x) == int(x):
        return np.nan
    return None


FUNCTIONS = {
    "log_gamma": (_log_gamma_real, _log_gamma_special),
    "digamma": (_digamma_real, _digamma_special),
}


def _grid(dtype) -> np.ndarray:
    fi = np.finfo(dtype)
    rng = np.random.default_rng(SEED)
    parts = [
        # Probe points asserted in tests, and the spec's special values.
        np.array([1.0, 2.0, 0.5, 1.5, -1.0, -2.0, 0.0, -0.0, np.inf, -np.inf, np.nan]),
        # Algorithm-boundary neighborhoods (thresholds at 3, 8, 10, 13).
        np.linspace(0.9, 3.1, 800),
        np.linspace(2.9, 13.5, 800),
        # Reflection territory and pole neighborhoods.
        np.linspace(-30.0, -0.01, 1200),
        np.concatenate([
            -k + off
            for k in range(0, 25)
            for off in (np.array([1e-3, 1e-6, 1e-9, -1e-3, -1e-6, -1e-9]),)
        ]),
        # Digamma's positive zero neighborhood.
        np.linspace(1.35, 1.6, 400),
        # Log-spaced large/small positives up to overflow country.
        np.logspace(np.log10(fi.tiny), np.log10(fi.max) - 1, 1500),
        # Seeded uniform coverage.
        rng.uniform(-50, 50, 6000),
        rng.uniform(-1e4, 1e4, 2000),
    ]
    x = np.concatenate([np.asarray(p, dtype=np.float64) for p in parts])
    x = x.astype(dtype)
    # Drop duplicates but keep signed zeros and one NaN.
    finite = x[np.isfinite(x)]
    finite = np.unique(finite)
    specials = np.array([0.0, -0.0, np.inf, -np.inf, np.nan], dtype=dtype)
    return np.concatenate([finite[finite != 0.0], specials]).astype(dtype)


def build_table(fn: str, dtype):
    truth, special = FUNCTIONS[fn]
    x = _grid(dtype)
    expected = np.empty_like(x)
    with mp.workdps(DPS):
        for i, xi in enumerate(x):
            s = special(float(xi))
            if s is not None:
                expected[i] = dtype(s)
                continue
            expected[i] = _round_to(truth(mp.mpf(float(xi))), dtype)
    return x, expected


def main() -> None:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for fn in FUNCTIONS:
        for dtype, name in ((np.float64, "float64"), (np.float32, "float32")):
            x, expected = build_table(fn, dtype)
            np.savez_compressed(OUT_DIR / f"{fn}_{name}.npz", x=x, expected=expected)
            print(f"{fn}_{name}: {x.size} points")


if __name__ == "__main__":
    main()
