"""Checked-in generated artifacts must be exactly reproducible.

Guards the spec rule that generated headers are never hand-edited: rerun
both generators into a temp dir and require byte-identical output.
Marked slow: mpmath fits take a couple of minutes.
"""

import numpy as np
import pytest

from tools.coefficients import generate as coeff_gen
from tools.references import generate as ref_gen


@pytest.mark.slow
def test_coefficient_headers_reproducible(tmp_path, monkeypatch):
    monkeypatch.setattr(coeff_gen, "OUT_DIR", tmp_path)
    coeff_gen.main()
    for fresh in tmp_path.iterdir():
        checked_in = coeff_gen.ROOT / "special_functions_cpu" / "generated" / fresh.name
        assert checked_in.read_bytes() == fresh.read_bytes(), fresh.name


@pytest.mark.slow
def test_reference_tables_reproducible(tmp_path, monkeypatch):
    monkeypatch.setattr(ref_gen, "OUT_DIR", tmp_path)
    ref_gen.main()
    for fresh in tmp_path.iterdir():
        checked_in = np.load(ref_gen.ROOT / "tests" / "references" / fresh.name)
        new = np.load(fresh)
        np.testing.assert_array_equal(checked_in["x"], new["x"])
        np.testing.assert_array_equal(checked_in["expected"], new["expected"])
