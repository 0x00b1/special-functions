cmake_minimum_required(VERSION 4.0.1)

project(special_functions)

set(CMAKE_CXX_STANDARD 23)

add_library(
        special_functions
        INTERFACE
        include/special_functions.h
)

target_include_directories(special_functions INTERFACE include)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# TODO: Re-enable RapidCheck after resolving compilation issues
# FetchContent_Declare(
#         rapidcheck
#         GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
#         GIT_TAG        master
# )
# 
# # Enable Google Test integration for RapidCheck
# set(RC_ENABLE_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Collect all unit test files
file(GLOB_RECURSE UNIT_TEST_SOURCES "test/*_test.cpp")

add_executable(
        special_functions_test
        ${UNIT_TEST_SOURCES}
)

target_link_libraries(
        special_functions_test
        GTest::gtest_main
        special_functions
        # rapidcheck_gtest  # TODO: Re-enable after fixing compilation issues
)

include(GoogleTest)

gtest_discover_tests(special_functions_test)
