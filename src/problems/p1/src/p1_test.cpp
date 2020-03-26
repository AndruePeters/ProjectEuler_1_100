///
/// \author Andrue Peters
/// \date 3/25/20
///
/// \brief GTest file for Problem 1
///
#include <p1.h>

#include <gtest/gtest.h>

TEST(ProjectEuler, Problem1)
{
    const int ProjectEulerAnswer = 233168;
    ASSERT_EQ(ProjectEulerAnswer, p1_partial_sum_formula(1000));
}