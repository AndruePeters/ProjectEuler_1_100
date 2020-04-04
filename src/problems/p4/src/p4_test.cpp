///
/// \author Andrue Peters
/// \date 4/2/20
///

#include <p4.h>

#include <gtest/gtest.h>

TEST(ProjectEuler, Problem4)
{
    const unsigned ProjectEulerAnswer = 906'609;
    const unsigned digit_length = 3;
    ASSERT_EQ(ProjectEulerAnswer, largest_palindrome(digit_length));
}

