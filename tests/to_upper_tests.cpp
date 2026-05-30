#include "../include/to_upper.h"
#include <gtest/gtest.h>

TEST(test, test_to_upper) {
    constexpr auto c = to_upper('c');
    ASSERT_TRUE(c == 'C');
}