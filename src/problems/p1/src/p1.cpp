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
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}

int p1_reduce_seq_vector(const std::vector<int>& v)
{
    return std::reduce(std::execution::seq, v.begin(), v.end());
}

int p1_reduce_unseq_vector(const std::vector<int>& v)
{
    return std::reduce(std::execution::unseq, v.begin(), v.end());
}

int p1_reduce_par_vector(const std::vector<int>& v)
{
    return std::reduce(std::execution::par, v.begin(), v.end());
}

int p1_reduce_par_unseq_vector(const std::vector<int>& v)
{
    return std::reduce(std::execution::par_unseq, v.begin(), v.end());
}

int p1_partial_sum_formula(const int upperBound)
{
    int sumMult3 = 3 * finite_sum(upperBound / 3);
    int sumMult5 = 5* finite_sum(upperBound / 5);
    int sumMult15 = 15 * finite_sum(upperBound / 15);
    return sumMult3 + sumMult5 - sumMult15;
}

std::vector<int> generateVector(const int upperBound)
{
    std::vector<int> v(upperBound);
    std::iota(v.begin(), v.end(), 1);
    return v;
}


