cmake_minimum_required(VERSION 3.23)

project(special_functions)

set(CMAKE_CXX_STANDARD 23)

add_library(
        special_functions
        INTERFACE
        include/special_functions.h
        include/special_functions/detail/eulerian_number_2_by_recursion.h include/special_functions/detail/stirling_number_s_2_by_series_expansion.h include/special_functions/detail/stirling_number_s_2_by_recursion.h include/special_functions/detail/stirling_number_s_1_by_recursion.h include/special_functions/detail/lah_number_by_recursion.h)

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
