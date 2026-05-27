cmake_minimum_required(VERSION 3.31)
project(to_upper)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_SANITIZER "address")
set(CMAKE_CXX_SANITIZER "undefined")

add_library(to_upper STATIC src/to_upper.cpp)

target_include_directories(to_upper
        PRIVATE
            src/to_upper.cpp
        PUBLIC
            include/to_upper.h
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(to_upper_tests tests/to_upper_tests.cpp)

target_link_libraries(to_upper_tests PRIVATE gtest_main to_upper)

include(GoogleTest)
gtest_discover_tests(to_upper_tests)