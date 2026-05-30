#include "../include/to_upper.h"
#include <gtest/gtest.h>
#include <string>
#include <algorithm>
#include <array>

TEST(test, test_to_upper1) {
    constexpr auto c = to_upper('c');
    ASSERT_TRUE(c == 'C');
}

TEST(test, test_to_upper2) {
    constexpr auto c = to_upper('z');
    ASSERT_TRUE(c == 'Z');
}

TEST(test, test_to_upper3) {
    constexpr auto c = to_upper('A');
    ASSERT_TRUE(c == 'A');
}

TEST(test, test_to_upper4) {
    constexpr auto c = to_upper('1');
    ASSERT_TRUE(c == '1');
}

TEST(test, test_to_upper5) {
    constexpr auto c = to_upper('\n');
    ASSERT_TRUE(c == '\n');
}

TEST(test, test_upper_literal1) {
    constexpr auto result = "test"_upper;
    constexpr std::string expected = "TEST";
    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), result.begin()));
}

TEST(test, test_upper_literal2) {
    constexpr auto result = "test2"_upper;
    constexpr std::string expected = "TEST2";
    ASSERT_TRUE(std::equal(expected.begin(), expected.end(), result.begin()));
}

