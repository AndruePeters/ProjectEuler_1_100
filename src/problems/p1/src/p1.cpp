///
/// \author Andrue Peters
/// \date 1/29/20
/// 
/// \brief Implementation for Problem 1
///

#include <iostream>

#include <p1.h>
#include <gen_math.h> 

int p1_partial_sum_formula(const int upperBound)
{
    const int limit = upperBound - 1;
    const int sumMult3 =   3 * math::consecutive_sum(limit / 3);
    const int sumMult5 =   5 * math::consecutive_sum(limit / 5);
    const int sumMult15 = 15 * math::consecutive_sum(limit / 15);
    return sumMult3 + sumMult5 - sumMult15;
}

