cmake_minimum_required(VERSION 3.16)
project(lab_01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(lab01_lib STATIC src/funcs.cpp)
target_include_directories(lab01_lib PUBLIC src)

add_executable(lab01_tests tests/tests_funcs.cpp)
target_link_libraries(lab01_tests PRIVATE lab01_lib GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab01_tests)