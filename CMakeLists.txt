cmake_minimum_required(VERSION 3.23)

project(special_functions)

set(CMAKE_CXX_STANDARD 23)

add_library(
        special_functions
        INTERFACE
        include/special_functions.h
        include/special_functions/factorial.h
        include/special_functions/detail/complex_util.h include/special_functions/detail/incomplete_gamma_by_series_summation.h include/special_functions/detail/incomplete_gamma_by_continued_fraction.h include/special_functions/detail/digamma_by_series_summation.h include/special_functions/detail/digamma_by_asymptotic_expansion.h)

target_include_directories(special_functions INTERFACE include)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        special_functions_test
        test/special_functions_test.cpp
)

target_link_libraries(
        special_functions_test
        GTest::gtest_main
        special_functions
)

include(GoogleTest)

gtest_discover_tests(special_functions_test)
