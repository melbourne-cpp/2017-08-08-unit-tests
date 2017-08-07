#include "../factorial.h"
#include "gtest/gtest.h"

TEST(factorial_recursive, handlesInt) {
    EXPECT_EQ(1L, factorial_recursive(0L));
    EXPECT_EQ(1L, factorial_recursive(1L));
    EXPECT_EQ(2L, factorial_recursive(2L));
    EXPECT_EQ(6L, factorial_recursive(3L));
    EXPECT_EQ(24L, factorial_recursive(4L));
    EXPECT_EQ(120L, factorial_recursive(5L));
    EXPECT_EQ(720L, factorial_recursive(6L));
    EXPECT_EQ(5040L, factorial_recursive(7L));
    EXPECT_EQ(40320L, factorial_recursive(8L));
    EXPECT_EQ(362880L, factorial_recursive(9L));
    EXPECT_EQ(3628800L, factorial_recursive(10L));
    EXPECT_EQ(39916800L, factorial_recursive(11L));
    EXPECT_EQ(479001600L, factorial_recursive(12L));
    EXPECT_EQ(6227020800L, factorial_recursive(13L));
    EXPECT_EQ(87178291200L, factorial_recursive(14L));
    EXPECT_EQ(1307674368000L, factorial_recursive(15L));
    EXPECT_EQ(20922789888000L, factorial_recursive(16L));
    EXPECT_EQ(355687428096000L, factorial_recursive(17L));
    EXPECT_EQ(6402373705728000L, factorial_recursive(18L));
    EXPECT_EQ(121645100408832000L, factorial_recursive(19L));
    EXPECT_EQ(2432902008176640000L, factorial_recursive(20L));
}
