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

#### 1. Create the Detail Implementation Header
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

#### 5. Add Tests
Edit `test/special_functions_test.cpp`:
```cpp
TEST(function_name_test, accuracy) {
    EXPECT_EQ(special_functions::function_name(0.0), expected_value);
    EXPECT_NEAR(special_functions::function_name(1.0), expected_value, 1e-10);
}

TEST(function_name_test, special_cases) {
    // Test NaN, infinity, edge cases
    EXPECT_TRUE(std::isnan(special_functions::function_name(std::numeric_limits<double>::quiet_NaN())));
}
```

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
- [ ] Detail implementation with robust numerics
- [ ] Public interface with proper type promotion
- [ ] Added to main header in alphabetical order
- [ ] Added to CMakeLists.txt
- [ ] Comprehensive tests added
- [ ] Tests pass locally
- [ ] CI tests pass