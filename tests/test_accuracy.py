"""Table-driven ULP contract: every implemented (function, dtype) pair must
match the checked-in mpmath truth within budgets.toml."""

import sys
from pathlib import Path

import numpy as np
import pytest

if sys.version_info >= (3, 11):
    import tomllib
else:
    import tomli as tomllib

from tests._harness.ulp import ulp_distance

REF_DIR = Path(__file__).parent / "references"
BUDGETS = tomllib.loads((REF_DIR / "budgets.toml").read_text())

IMPLEMENTED = [
    ("log_gamma", "float64"),
    ("log_gamma", "float32"),
    ("digamma", "float64"),
    ("digamma", "float32"),
]


def _budget_masks(fn, dtype, x):
    spec = BUDGETS[fn][dtype]
    budget = np.full(x.shape, spec["default"], dtype=object)
    atol = np.zeros(x.shape)
    for region in spec.get("regions", ()):
        m = (x >= region["lo"]) & (x <= region["hi"])
        if "ulp" in region:
            budget[m] = region["ulp"]
        else:
            budget[m] = None  # atol-governed
            atol[m] = region["atol"]
    return budget, atol


@pytest.mark.parametrize("fn,dtype", IMPLEMENTED)
def test_ulp_budget(sf_cpu, fn, dtype):
    table = np.load(REF_DIR / f"{fn}_{dtype}.npz")
    x, expected = table["x"], table["expected"]
    got = sf_cpu.call(fn, dtype, x)

    # Specials must match exactly: same NaN-ness, same infinities (with sign).
    special = ~np.isfinite(expected)
    assert np.array_equal(np.isnan(got[special]), np.isnan(expected[special]))
    inf_mask = np.isinf(expected)
    assert np.array_equal(got[inf_mask], expected[inf_mask])
    # Finite expecteds must produce finite results.
    finite = np.isfinite(expected)
    assert np.isfinite(got[finite]).all(), (
        f"non-finite outputs at x={x[finite][~np.isfinite(got[finite])][:10]}"
    )

    budget, atol = _budget_masks(fn, dtype, x)
    fx, fexp, fgot = x[finite], expected[finite], got[finite]
    fbud, fatol = budget[finite], atol[finite]

    ulp_gov = np.array([b is not None for b in fbud])
    d = ulp_distance(fgot[ulp_gov], fexp[ulp_gov])
    limits = np.array([int(b) for b in fbud[ulp_gov]], dtype=object)
    bad = d > limits
    assert not bad.any(), (
        f"{fn}/{dtype}: {bad.sum()} points over budget; worst "
        f"{max(d[bad])} ULP at x={fx[ulp_gov][bad][np.argmax(d[bad])]}"
    )

    a = ~ulp_gov
    if a.any():
        err = np.abs(fgot[a].astype(np.float64) - fexp[a].astype(np.float64))
        assert (err <= fatol[a]).all(), (
            f"{fn}/{dtype}: atol regions exceeded; worst {err.max()}"
        )
