///
/// \author Andrue Peters
/// \date 3/25/20
///
/// \brief GTest file for Problem 2
///

#include <p2.h>

#include <gtest/gtest.h>

TEST(ProjectEuler, Problem2)
{
    const int ProjectEulerAnswer = 4613732;
    const unsigned fib_limit = 4'000'000;
    ASSERT_EQ(ProjectEulerAnswer, even_fibonacci_sum(fib_limit));
}

