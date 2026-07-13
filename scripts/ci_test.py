# /// script
# dependencies = ["kernels", "torch"]
# ///
"""CI smoke test: pull the published kernel from the Hub and exercise it.

Runs on an HF Jobs GPU via .github/workflows/run-tests.yml. The full
ULP/property suite lives in tests/ and runs via `nix run .#ci-test`; this
script guards the published Hub artifacts end-to-end (load, dispatch,
sanity values, autograd).
"""

import torch
from kernels import get_kernel

special_functions = get_kernel("0x00b1/special-functions", version=1)

device = torch.device("cuda")

x = torch.tensor([0.5, 1.0, 2.0, 3.5], dtype=torch.float64, device=device)

# Γ(1) = 1, Γ(2) = 1; ψ(1) = -euler_gamma.
gamma = special_functions.gamma(x)
torch.testing.assert_close(
    gamma,
    torch.tensor(
        [1.7724538509055160, 1.0, 1.0, 3.3233509704478426],
        dtype=torch.float64,
        device=device,
    ),
)

log_gamma = special_functions.log_gamma(x)
torch.testing.assert_close(log_gamma, gamma.log())

digamma = special_functions.digamma(torch.ones_like(x))
torch.testing.assert_close(
    digamma, torch.full_like(x, -0.5772156649015329)
)

# Autograd: d/dx log_gamma = digamma.
x_grad = x.clone().requires_grad_(True)
special_functions.log_gamma(x_grad).sum().backward()
torch.testing.assert_close(x_grad.grad, special_functions.digamma(x))

print("ok")
