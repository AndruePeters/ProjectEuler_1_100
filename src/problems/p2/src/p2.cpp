#include "p2.h"

#include <boost/container/flat_map.hpp>
#include <unsupported/Eigen/MatrixFunctions>
#include <unsupported/Eigen/src/MatrixFunctions/MatrixExponential.h>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <iostream>
#include <cmath>
#include <numeric>

unsigned fib_recursive(const unsigned n)
{
    if (n <= 1) return 1;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

/**
 * Uses memoization to speed up functionality.
 */
unsigned fib_memoization(const unsigned n)
{
    static boost::container::flat_map<unsigned, unsigned> fib_map {{0, 0}, {1, 1}, {2, 1}};

    auto it = fib_map.find(n);
    if (it == fib_map.end()) {
        fib_map[n] = fib_memoization(n - 1) + fib_memoization(n - 2);
        return fib_map[n];
    } else {
        return it->second;
    }
}

/**
 * Uses memoization to speed up functionality.
 * Same as above, but prioritizes item existing.
 */
unsigned fib_memoization_revIf(const unsigned n)
{
    static boost::container::flat_map<unsigned, unsigned> fib_map {{0, 0}, {1, 1}, {2, 1}};

    auto it = fib_map.find(n);
    if (it != fib_map.end()) {
        return it->second;
    } else {
        return fib_map[n] = fib_memoization_revIf(n - 1) + fib_memoization_revIf(n - 2);
    }
}

unsigned fib_loop(const unsigned n)
{
    unsigned n1 = 0, n2 = 1;
    for (unsigned i = 0; i < n; ++i) {
            unsigned fib = n1 + n2;
            n1 = n2;
            n2 = fib;
    }
    return n2;
}

/**
 * Don't call if n is < 2
 */
unsigned fib_dynamic(const unsigned n)
{
    std::vector<unsigned> fibs(n+1);
    fibs[0] = 0;
    fibs[1] = 1;

    for (unsigned fib = 2; fib <= n; ++fib) {
        fibs[fib] = fibs[fib-1] + fibs[fib-2];
    }

    return fibs[n];
}

unsigned fib_golden_ratio(const unsigned n)
{
    // golden ratio
    const double sqrt5 = std::sqrt(5);
    const double gr = (1 + sqrt5) / 2;
    const double grPow = std::pow(gr, n);
    return std::floor( (grPow / sqrt5) + (1/2));
}

/**
 * | 1 1 | ^ n = | F(n+1)  Fn     |
 * | 1 0 |       | F(n)    F(n-1) |
 */
unsigned fib_eigen_matrix_exp(const unsigned n)
{
    using namespace Eigen;
    Matrix2f matrix;

    matrix <<   1, 1,
                1, 0;
    auto powMatrix = matrix;
    MatrixPower<Matrix2f> mPow(matrix);
    mPow.compute(powMatrix, n-1);
    return powMatrix(0, 0);
}

unsigned fib_eigen_matrix_exp_fast(const unsigned n)
{
    using namespace Eigen;
    Matrix2f m;
    m << 1, 1,
         1, 0;

    auto p = m.pow( std::floor(n/2));
    if ((n & 0x01) == 0) {
        return (p * p)(0, 1);
    } else {
        return (p * p * m)(0,1);
    }
}

unsigned fib_sum_memoization(const unsigned fib_limit)
{
    return fib_sum(fib_limit, fib_memoization_revIf);
}

unsigned fib_sum_eigen_matrix(const unsigned fib_limit)
{
    return fib_sum(fib_limit, fib_eigen_matrix_exp);
}

unsigned fib_sum_golden_ratio(const unsigned fib_limit)
{
    return fib_sum(fib_limit, fib_golden_ratio);
}


unsigned fib_sum(const unsigned fib_limit, std::function<unsigned (unsigned)> fib_func)
{
    std::vector<unsigned> fib_values;
    fib_values.reserve(1000);

    // first even is 2, so start with that
    unsigned fib = 2;

    // every even fib number has index multiple of 3, but we already started with fib(3) = 2, 
    // so jump to next even index
    unsigned i = 6;

    // loop is setup so that it adds the previous fib value to the vector
    // and then calculates the new one
    // after the new number is calculated, it's coompared within the while section
    while (fib < fib_limit) {
        fib_values.push_back(fib);
        fib = fib_func(i);
        i += 3;
    }

    return std::reduce(fib_values.begin(), fib_values.end());
}
