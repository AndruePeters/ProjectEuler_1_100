#ifndef P1_TEST_H
#define P1_TEST_H

#include "p1.h"
#include <gtest/gtest.h>


TEST(Problem1, SumOf3_5_Multiples)
{
    EXPECT_EQ(p1_loop_constexpr(1000), 233168) << "Expected 233168."
    EXPECT_EQ(p1_rawloop_vector(1000), 233168) << "Expected 233168."
    EXPECT_EQ(p1_partial_sum_formula(1000), 233168) << "Expected 233168."
}
#endif