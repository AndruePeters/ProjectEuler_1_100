#include <p2.h>

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

int main()
{
    const unsigned fib_limit = 4'000'000;
    std::cout << "fib_sum_memoization: " << fib_sum_memoization(fib_limit) << std::endl;
    std::cout << "fib_sum_eigen_matrix: " << fib_sum_eigen_matrix(fib_limit) << std::endl;
    std::cout << "fib_sum_golden_ratio: " << fib_sum_golden_ratio(fib_limit) << std::endl;
    return 0;
}
