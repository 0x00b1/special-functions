# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build and Development Commands

### Building
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

### Testing  
```bash
ctest -C Release
# Working directory: build/
```

### Running Single Tests
The project uses GoogleTest. To run specific tests:
```bash
./build/special_functions_test --gtest_filter="cos_pi_test.accuracy"
```

## Architecture Overview

This is a **header-only C++23 library** providing mathematical special functions. The architecture follows a clean separation:

### Core Structure
- **Main header**: `include/special_functions.h` - Single include point for all functions
- **Individual headers**: `include/special_functions/*.h` - Each function has its own header
- **Implementation details**: `include/special_functions/detail/*.h` - Internal implementation helpers
- **Type utilities**: `include/special_functions/detail/fp_type_util.h` - Core type promotion and utilities

### Key Design Patterns
- **Header-only**: All functionality in headers, no compiled libraries
- **Template-based**: Extensive use of templates for type safety and performance
- **Type promotion**: Automatic promotion of integral types to floating-point as needed
- **Namespace organization**: All functions in `special_functions` namespace
- **INTERFACE library**: CMake INTERFACE library pattern for header-only distribution

### Special Functions Categories
The library implements 150+ mathematical special functions across categories:
- **Basic functions**: gamma, beta, factorial variants
- **Bessel functions**: regular, modified, spherical variants  
- **Polynomials**: Chebyshev, Legendre, Hermite, Laguerre, etc.
- **Hypergeometric functions**: confluent and Gauss hypergeometric
- **Elliptic functions**: complete and incomplete integrals
- **Number theory**: prime numbers, Stirling numbers, Euler numbers
- **Special integrals**: Fresnel, exponential, sine/cosine integrals

### Development Considerations
- **C++23 requirement**: Uses modern C++ features including `std::numbers`
- **GoogleTest integration**: Automatically fetched via FetchContent
- **Cross-platform**: Designed to work across different platforms
- **GitHub Actions**: Automated testing on Ubuntu latest with Release builds

## Guide to Implementing New Special Functions

### Step-by-Step Implementation Process

#### 1. Write Unit Tests First (Test-Driven Development)

**ALWAYS START WITH TESTS** - This ensures you understand the mathematical requirements and expected behavior before implementation.

Create comprehensive tests in `test/special_functions_test.cpp`:

```cpp
// Test mathematical accuracy with known values
TEST(function_name_test, known_values) {
    // Test exact values where the function has known results
    EXPECT_DOUBLE_EQ(special_functions::function_name(0.0), 1.0);  // example
    EXPECT_DOUBLE_EQ(special_functions::function_name(1.0), 2.718281828);  // example
    
    // Test values from mathematical reference tables
    EXPECT_NEAR(special_functions::function_name(0.5), 1.6487212707, 1e-10);
    EXPECT_NEAR(special_functions::function_name(2.0), 7.3890560989, 1e-10);
}

// Test special mathematical cases
TEST(function_name_test, special_cases) {
    // Test behavior at mathematical singularities or special points
    EXPECT_EQ(special_functions::function_name(0.0), expected_at_zero);
    
    // Test positive/negative infinity behavior
    EXPECT_EQ(special_functions::function_name(std::numeric_limits<double>::infinity()), 
              std::numeric_limits<double>::infinity());
    EXPECT_EQ(special_functions::function_name(-std::numeric_limits<double>::infinity()), 
              expected_negative_infinity_result);
    
    // Test NaN propagation
    EXPECT_TRUE(std::isnan(special_functions::function_name(std::numeric_limits<double>::quiet_NaN())));
}

// Test edge cases and boundary conditions
TEST(function_name_test, edge_cases) {
    // Test very small values (near underflow)
    EXPECT_NEAR(special_functions::function_name(1e-100), expected_small_value, 1e-15);
    
    // Test very large values (near overflow)
    EXPECT_NEAR(special_functions::function_name(100.0), expected_large_value, 1e-10);
    
    // Test negative values if applicable
    EXPECT_NEAR(special_functions::function_name(-1.0), expected_negative_value, 1e-10);
}

// Test type promotion and different numeric types
TEST(function_name_test, type_promotion) {
    // Test that integers are promoted to floating-point
    EXPECT_DOUBLE_EQ(special_functions::function_name(1), special_functions::function_name(1.0));
    
    // Test float precision
    float result_f = special_functions::function_name(1.0f);
    EXPECT_NEAR(result_f, expected_float_result, 1e-6f);
    
    // Test long double precision if relevant
    long double result_ld = special_functions::function_name(1.0L);
    EXPECT_NEAR(result_ld, expected_long_double_result, 1e-18L);
}

// Test complex number support (if applicable)
TEST(function_name_test, complex_support) {
    std::complex<double> z(1.0, 1.0);
    std::complex<double> result = special_functions::function_name(z);
    
    EXPECT_NEAR(std::real(result), expected_real_part, 1e-10);
    EXPECT_NEAR(std::imag(result), expected_imaginary_part, 1e-10);
    
    // Test pure imaginary input
    std::complex<double> i_z(0.0, 1.0);
    std::complex<double> i_result = special_functions::function_name(i_z);
    // Assert expected behavior for pure imaginary input
}

// Test numerical stability across input ranges
TEST(function_name_test, numerical_stability) {
    // Test that function maintains accuracy across different ranges
    for (double x = 0.1; x < 10.0; x += 0.1) {
        double result = special_functions::function_name(x);
        EXPECT_FALSE(std::isnan(result)) << "Function returned NaN for x = " << x;
        EXPECT_FALSE(std::isinf(result)) << "Function returned infinity for x = " << x;
    }
}
```

**Testing Strategy Details:**

1. **Mathematical Verification**:
   - Use known exact values (e.g., function(0) = 1 for many functions)
   - Reference values from mathematical handbooks (Abramowitz & Stegun, DLMF, etc.)
   - Cross-check with established mathematical software (Mathematica, MATLAB, GSL)

2. **Boundary Testing**:
   - Test at domain boundaries (if function has restricted domain)
   - Test asymptotic behavior (x → 0, x → ∞)
   - Test discontinuities or branch cuts for complex functions

3. **Error Propagation**:
   - Verify NaN inputs produce NaN outputs
   - Test infinity handling according to mathematical definition
   - Ensure no unexpected exceptions are thrown

4. **Precision Testing**:
   - Test different floating-point precisions (float, double, long double)
   - Verify type promotion works correctly for integer inputs
   - Test that precision is maintained throughout computation

5. **Performance Indicators**:
   - Tests should run quickly (avoid slow convergence algorithms in tests)
   - Use reasonable tolerances (typically 1e-10 for double precision)

**Run Tests Before Implementation:**
```bash
# Tests will initially fail - this is expected and desired
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
ctest -C Release --verbose
```

The failing tests guide your implementation and ensure you meet all mathematical requirements.

#### 2. Create the Detail Implementation Header
Create `include/special_functions/detail/function_name.h`:

```cpp
#ifndef SPECIAL_FUNCTIONS_DETAIL_FUNCTION_NAME_H
#define SPECIAL_FUNCTIONS_DETAIL_FUNCTION_NAME_H

#include <special_functions/detail/fp_type_util.h>
#include <cmath>
#include <complex>
#include <numbers>
#include <limits>

namespace special_functions::detail {
    template<typename T>
    T function_name(T x) {
        using U = special_functions::num_traits_t<T>;
        
        // Handle special cases (NaN, infinity, etc.)
        if (std::isnan(x)) return std::numeric_limits<T>::quiet_NaN();
        
        // Your mathematical implementation here
        // Use std::numbers::pi_v<U> for π constants
        // Use appropriate numerical algorithms
        
        return result;
    }
    
    // Complex version if applicable
    template<typename T>
    std::complex<T> function_name(std::complex<T> z) {
        // Complex implementation
        return result;
    }
}

#endif
```

#### 2. Create the Public Interface Header
Create `include/special_functions/function_name.h`:

```cpp
#ifndef SPECIAL_FUNCTIONS_FUNCTION_NAME_H
#define SPECIAL_FUNCTIONS_FUNCTION_NAME_H

#include <special_functions/detail/function_name.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    function_name(T x) {
        using U = fp_promote_t<T>;
        return detail::function_name<U>(x);
    }
    
    // Complex overload if applicable
    template<typename T>
    std::complex<T>
    function_name(std::complex<T> z) {
        return detail::function_name(z);
    }
}

#endif
```

#### 3. Add to Main Header
Edit `include/special_functions.h`:
- Add `#include <special_functions/function_name.h>` in alphabetical order
- The main header provides the single-include interface

#### 4. Add to CMakeLists.txt
Edit `CMakeLists.txt` to include both header files in the INTERFACE library:
```cmake
add_library(
    special_functions
    INTERFACE
    # ... existing files ...
    include/special_functions/function_name.h
    include/special_functions/detail/function_name.h
)
```

#### 5. Verify Tests Pass
Run the complete test suite to ensure your implementation works correctly:

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
ctest -C Release --verbose

# Run specific function tests
./build/special_functions_test --gtest_filter="function_name_test.*"
```

The tests you wrote in step 1 should now all pass, confirming your implementation meets the mathematical requirements.

### Implementation Guidelines

#### Type Safety and Promotion
- Use `fp_promote_t<T>` for automatic type promotion from integral to floating-point types
- Use `num_traits_t<T>` to extract underlying value type for complex numbers
- Always handle both real and complex number cases where mathematically valid

#### Numerical Accuracy
- Implement robust algorithms that handle edge cases (0, infinity, very large/small values)
- Use appropriate series expansions, continued fractions, or asymptotic expansions
- Consider different algorithms for different input ranges to maintain accuracy

#### Error Handling
- Return `std::numeric_limits<T>::quiet_NaN()` for invalid inputs
- Handle infinity cases appropriately based on mathematical definition
- Use `std::isnan()`, `std::isinf()` for input validation

#### Performance Considerations
- Mark functions `constexpr` where possible for compile-time evaluation
- Use template specializations for performance-critical cases
- Avoid unnecessary computations and leverage mathematical identities

#### Documentation Pattern
Functions should be self-documenting through clear naming. The library follows mathematical naming conventions closely.

### Testing Strategy
- Test accuracy against known values
- Test special cases (0, ±∞, NaN)
- Test edge cases specific to the function's domain
- Compare with reference implementations where available
- Test both real and complex variants

### Integration Checklist
- [ ] **Comprehensive tests written FIRST** (covers all cases and mathematical requirements)
- [ ] Tests initially fail (before implementation)
- [ ] Detail implementation with robust numerics
- [ ] Public interface with proper type promotion
- [ ] Added to main header in alphabetical order
- [ ] Added to CMakeLists.txt
- [ ] **All tests now pass** (implementation meets requirements)
- [ ] Tests pass locally with all precision types
- [ ] CI tests pass on GitHub Actions

### Why Test-First Development Matters

1. **Mathematical Correctness**: Writing tests first forces you to research and understand the exact mathematical behavior, including special cases and edge conditions.

2. **Comprehensive Coverage**: You identify all the scenarios that need testing before getting caught up in implementation details.

3. **Reference Implementation**: Tests serve as executable specifications, making it clear what the function should do in every case.

4. **Regression Prevention**: Future changes to the implementation or underlying libraries won't break existing functionality.

5. **Documentation**: Well-written tests serve as usage examples and documentation for other developers.

6. **Implementation Guidance**: Failing tests guide your implementation priorities - you know exactly what cases need to work.

## Property-Based Testing for Special Functions

Beyond unit tests with specific values, **property-based tests** verify mathematical relationships and invariants that should hold across ranges of inputs. These tests are crucial for special functions because they validate the underlying mathematical structure.

### Essential Mathematical Properties to Test

#### 1. Symmetry Properties
Many special functions have inherent symmetries:

```cpp
TEST(function_name_test, symmetry_properties) {
    // Even function: f(-x) = f(x)
    for (double x = 0.1; x <= 10.0; x += 0.1) {
        EXPECT_NEAR(special_functions::function_name(-x), 
                    special_functions::function_name(x), 1e-14)
            << "Even symmetry violated at x = " << x;
    }
    
    // Odd function: f(-x) = -f(x)
    for (double x = 0.1; x <= 10.0; x += 0.1) {
        EXPECT_NEAR(special_functions::function_name(-x), 
                    -special_functions::function_name(x), 1e-14)
            << "Odd symmetry violated at x = " << x;
    }
    
    // Period symmetry: f(x + T) = f(x) for periodic functions
    const double period = M_PI; // example
    for (double x = 0.0; x <= 10.0; x += 0.1) {
        EXPECT_NEAR(special_functions::function_name(x + period),
                    special_functions::function_name(x), 1e-14)
            << "Periodicity violated at x = " << x;
    }
}
```

#### 2. Recurrence Relations
Many special functions satisfy recurrence relations:

```cpp
TEST(function_name_test, recurrence_relations) {
    // Example: Gamma function recurrence Γ(x+1) = x·Γ(x)
    for (double x = 0.5; x <= 10.0; x += 0.1) {
        double gamma_x = special_functions::gamma(x);
        double gamma_x_plus_1 = special_functions::gamma(x + 1);
        EXPECT_NEAR(gamma_x_plus_1, x * gamma_x, 1e-13)
            << "Gamma recurrence failed at x = " << x;
    }
    
    // Example: Bessel function recurrence J_{n-1}(x) + J_{n+1}(x) = (2n/x)J_n(x)
    for (int n = 1; n <= 10; ++n) {
        for (double x = 0.1; x <= 20.0; x += 0.2) {
            double j_n_minus_1 = special_functions::bessel_j(n - 1, x);
            double j_n = special_functions::bessel_j(n, x);
            double j_n_plus_1 = special_functions::bessel_j(n + 1, x);
            
            EXPECT_NEAR(j_n_minus_1 + j_n_plus_1, (2.0 * n / x) * j_n, 1e-12)
                << "Bessel recurrence failed at n = " << n << ", x = " << x;
        }
    }
}
```

#### 3. Differential Equations
Special functions often satisfy characteristic differential equations:

```cpp
TEST(function_name_test, differential_equation_properties) {
    // Test that the function satisfies its defining differential equation
    // Example: Airy function Ai''(x) - x·Ai(x) = 0
    
    const double h = 1e-6; // finite difference step
    
    for (double x = -5.0; x <= 5.0; x += 0.1) {
        // Numerical second derivative
        double ai_minus = special_functions::airy_ai(x - h);
        double ai_center = special_functions::airy_ai(x);
        double ai_plus = special_functions::airy_ai(x + h);
        
        double second_derivative = (ai_plus - 2 * ai_center + ai_minus) / (h * h);
        double equation_residual = second_derivative - x * ai_center;
        
        EXPECT_NEAR(equation_residual, 0.0, 1e-8)
            << "Airy differential equation violated at x = " << x;
    }
}
```

#### 4. Functional Equations and Identities
Test mathematical identities that relate function values:

```cpp
TEST(function_name_test, functional_identities) {
    // Example: sin²(x) + cos²(x) = 1
    for (double x = 0.0; x <= 2 * M_PI; x += 0.01) {
        double sin_x = std::sin(x);
        double cos_x = std::cos(x);
        EXPECT_NEAR(sin_x * sin_x + cos_x * cos_x, 1.0, 1e-15)
            << "Pythagorean identity failed at x = " << x;
    }
    
    // Example: Γ(x)Γ(1-x) = π/sin(πx) for 0 < x < 1
    for (double x = 0.01; x <= 0.99; x += 0.01) {
        double gamma_x = special_functions::gamma(x);
        double gamma_1_minus_x = special_functions::gamma(1 - x);
        double reflection_formula = M_PI / std::sin(M_PI * x);
        
        EXPECT_NEAR(gamma_x * gamma_1_minus_x, reflection_formula, 1e-12)
            << "Gamma reflection formula failed at x = " << x;
    }
}
```

#### 5. Monotonicity and Convexity
Test function behavior properties:

```cpp
TEST(function_name_test, monotonicity) {
    // Test that function is monotonically increasing/decreasing on intervals
    std::vector<double> x_values;
    std::vector<double> function_values;
    
    for (double x = 0.1; x <= 10.0; x += 0.01) {
        x_values.push_back(x);
        function_values.push_back(special_functions::function_name(x));
    }
    
    // Test monotonic increasing
    for (size_t i = 1; i < function_values.size(); ++i) {
        EXPECT_GE(function_values[i], function_values[i-1])
            << "Function not monotonically increasing between x = " 
            << x_values[i-1] << " and x = " << x_values[i];
    }
}

TEST(function_name_test, convexity) {
    // Test convexity using second derivative test
    const double h = 1e-6;
    
    for (double x = 0.1; x <= 10.0; x += 0.1) {
        double f_minus = special_functions::function_name(x - h);
        double f_center = special_functions::function_name(x);
        double f_plus = special_functions::function_name(x + h);
        
        double second_derivative = (f_plus - 2 * f_center + f_minus) / (h * h);
        
        // Test convexity (f'' > 0) or concavity (f'' < 0) as appropriate
        EXPECT_GT(second_derivative, 0.0)
            << "Function not convex at x = " << x;
    }
}
```

#### 6. Scaling and Homogeneity Properties
Test scaling relationships:

```cpp
TEST(function_name_test, scaling_properties) {
    // Example: Homogeneous functions f(λx) = λⁿf(x)
    const double scale_factor = 2.0;
    const int homogeneity_degree = 1; // example
    
    for (double x = 0.1; x <= 10.0; x += 0.1) {
        double f_x = special_functions::function_name(x);
        double f_scaled_x = special_functions::function_name(scale_factor * x);
        double expected = std::pow(scale_factor, homogeneity_degree) * f_x;
        
        EXPECT_NEAR(f_scaled_x, expected, 1e-13)
            << "Scaling property violated at x = " << x;
    }
}
```

#### 7. Asymptotic Behavior
Test limiting behavior as parameters approach boundaries:

```cpp
TEST(function_name_test, asymptotic_behavior) {
    // Test x → 0⁺ behavior
    std::vector<double> small_values = {1e-1, 1e-2, 1e-3, 1e-4, 1e-5};
    for (size_t i = 1; i < small_values.size(); ++i) {
        double x_current = small_values[i];
        double x_previous = small_values[i-1];
        
        double f_current = special_functions::function_name(x_current);
        double f_previous = special_functions::function_name(x_previous);
        
        // Test that function approaches expected limit
        // Example: function approaches constant as x → 0
        double ratio = f_current / f_previous;
        EXPECT_NEAR(ratio, 1.0, 0.1) // Allow 10% deviation for convergence
            << "Asymptotic behavior inconsistent at x = " << x_current;
    }
    
    // Test x → ∞ behavior  
    std::vector<double> large_values = {10.0, 50.0, 100.0, 500.0};
    for (size_t i = 1; i < large_values.size(); ++i) {
        double x_current = large_values[i];
        double x_previous = large_values[i-1];
        
        // Test asymptotic growth rate
        double f_current = special_functions::function_name(x_current);
        double f_previous = special_functions::function_name(x_previous);
        
        // Example: exponential growth f(kx)/f(x) ≈ e^(c(kx-x))
        double expected_ratio = std::exp(/* asymptotic coefficient */ * (x_current - x_previous));
        EXPECT_NEAR(f_current / f_previous, expected_ratio, 0.1)
            << "Asymptotic growth rate incorrect at x = " << x_current;
    }
}
```

### Property Test Implementation Strategy

1. **Mathematical Research**: Before writing property tests, thoroughly research the mathematical properties your function should satisfy.

2. **Range Selection**: Choose test ranges that cover:
   - The function's natural domain
   - Areas where different algorithms might be used
   - Transition regions between different behaviors

3. **Tolerance Management**: Property tests often need looser tolerances than exact value tests due to accumulated numerical errors across computations.

4. **Complementary Testing**: Property tests complement but don't replace unit tests with known values. Use both approaches together.

5. **Documentation**: Comment property tests extensively to explain the mathematical basis being verified.

### Benefits of Property-Based Testing

- **Mathematical Rigor**: Verifies that implementations respect the underlying mathematical structure
- **Algorithm Validation**: Catches errors in numerical algorithms that might not show up in spot tests  
- **Range Coverage**: Tests behavior across continuous ranges rather than discrete points
- **Regression Detection**: Identifies when changes break fundamental mathematical relationships
- **Implementation Independence**: Tests mathematical truth rather than specific computational approaches

### Using RapidCheck for Automated Property Testing

For more sophisticated property-based testing, consider integrating **RapidCheck** - a QuickCheck-inspired library that integrates seamlessly with Google Test.

#### Setup RapidCheck Integration

Add to your `CMakeLists.txt`:

```cmake
# Add RapidCheck
include(FetchContent)

FetchContent_Declare(
    rapidcheck
    GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
    GIT_TAG        master
)

# Enable Google Test integration
set(RC_ENABLE_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(rapidcheck)

# Link against both GoogleTest and RapidCheck
target_link_libraries(
    special_functions_test
    GTest::gtest_main
    special_functions
    rapidcheck_gtest
)
```

#### RapidCheck Property Examples

```cpp
#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>  // Must come after gtest.h
#include <special_functions.h>

// Automatic test case generation for symmetry
RC_GTEST_PROP(gamma_test, reflection_formula_property, 
              (double x)) {
    // RapidCheck generates random values for x
    RC_PRE(x > 0.0 && x < 1.0); // Precondition
    
    double gamma_x = special_functions::gamma(x);
    double gamma_1_minus_x = special_functions::gamma(1.0 - x);
    double reflection_formula = M_PI / std::sin(M_PI * x);
    
    RC_ASSERT(std::abs(gamma_x * gamma_1_minus_x - reflection_formula) < 1e-12);
}

// Test monotonicity automatically
RC_GTEST_PROP(gamma_test, monotonicity_on_positive_reals,
              (double x1, double x2)) {
    RC_PRE(x1 > 0.0 && x2 > 0.0 && x1 < x2 && x2 < 10.0);
    
    double gamma_x1 = special_functions::gamma(x1);
    double gamma_x2 = special_functions::gamma(x2);
    
    // Gamma is increasing for x > 1.462...
    if (x1 > 1.5) {
        RC_ASSERT(gamma_x2 > gamma_x1);
    }
}

// Test recurrence relation with generated integers
RC_GTEST_PROP(factorial_test, recurrence_property,
              (int n)) {
    RC_PRE(n >= 1 && n <= 20); // Avoid overflow
    
    double fact_n = special_functions::factorial<double>(n);
    double fact_n_minus_1 = special_functions::factorial<double>(n - 1);
    
    RC_ASSERT(std::abs(fact_n - n * fact_n_minus_1) < 1e-12);
}

// Complex number properties
RC_GTEST_PROP(bessel_test, complex_conjugate_symmetry,
              (double real_part, double imag_part)) {
    RC_PRE(std::abs(real_part) < 10.0 && std::abs(imag_part) < 10.0);
    
    std::complex<double> z(real_part, imag_part);
    std::complex<double> z_conj = std::conj(z);
    
    auto bessel_z = special_functions::bessel_j(0, z);
    auto bessel_z_conj = special_functions::bessel_j(0, z_conj);
    
    // J_0(z*) = J_0(z)* for real order
    RC_ASSERT(std::abs(bessel_z_conj - std::conj(bessel_z)) < 1e-12);
}
```

#### Benefits of RapidCheck Integration

1. **Automatic Test Case Generation**: RapidCheck generates hundreds of random test cases automatically
2. **Shrinking**: When a property fails, RapidCheck finds the minimal failing case for easier debugging
3. **Preconditions**: Use `RC_PRE()` to specify valid input domains
4. **Seamless Integration**: Works within existing Google Test framework
5. **Customizable Generators**: Create custom generators for specific data types

#### Custom Generators Example

```cpp
#include <rapidcheck.h>

// Custom generator for positive definite matrices, special intervals, etc.
RC_GTEST_PROP(special_function_test, custom_domain_property, ()) {
    // Generate values in specific mathematical domains
    auto x = *rc::gen::inRange(0.1, 100.0);  // Positive reals
    auto n = *rc::gen::inRange(1, 50);       // Positive integers
    
    // Test your property with generated values
    RC_ASSERT(special_functions::your_function(x, n) > 0.0);
}
```

This approach combines the comprehensive manual property testing shown above with automated test case generation, providing both explicit mathematical verification and broad input space coverage.