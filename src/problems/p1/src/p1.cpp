#include <iostream>
#include <p1.h>

#include <numeric>
#include <vector>
#include <algorithm>
#include <execution>

int p1_loop(const int upperBound)
{
    int sum = 0;

    for (int i = 0; i < upperBound; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}


int p1_rawloop_vector(const std::vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < static_cast<int>(v.size()); ++i) { // I know there won't be a bound problem for my use case
        sum += v[static_cast<std::size_t>(i)];
    }
    return sum;
}

int p1_partial_sum_formula(const int upperBound)
{
    const int limit = upperBound - 1;
    int sumMult3 = 3 * finite_sum(limit / 3);
    int sumMult5 = 5* finite_sum(limit / 5);
    int sumMult15 = 15 * finite_sum(limit / 15);
    return sumMult3 + sumMult5 - sumMult15;
}

std::vector<int> generateVector(const int upperBound)
{
    std::vector<int> v(static_cast<size_t>(upperBound));
    std::iota(v.begin(), v.end(), 1);
    return v;
}


