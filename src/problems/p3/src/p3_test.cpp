///
/// \author Andrue Peters
/// \date 3/25/20
///

#include <p3.h>

#include <gtest/gtest.h>

TEST(ProjectEuler, Problem3)
{
    const int ProjectEulerAnswer = 6857;
    const unsigned long factorize = 600'851'475'143;
    ASSERT_EQ(ProjectEulerAnswer, largest_prime_factor(factorize));
}

