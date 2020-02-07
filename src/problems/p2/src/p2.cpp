#include "p2.h"

#include <boost/container/flat_map.hpp>
#include <unsupported/Eigen/MatrixFunctions>
#include <unsupported/Eigen/src/MatrixFunctions/MatrixExponential.h>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <iostream>

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
    static boost::container::flat_map<unsigned, unsigned> fib_map;
    fib_map.reserve(n);
    if (n <= 1) return 1;
    auto it = fib_map.find(n);
    if (it == fib_map.end()) {
        return fib_map[n] = fib_memoization(n - 1) + fib_memoization(n - 2);
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
    static boost::container::flat_map<unsigned, unsigned> fib_map;
    if (n <= 1) return 1;
    auto it = fib_map.find(n);
    if (it != fib_map.end()) {
        return it->second;
    } else {
        return fib_map[n] = fib_memoization(n - 1) + fib_memoization(n - 2);
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

unsigned fib_fast_matrix_exp(const unsigned n)
{
    using namespace Eigen;
    Matrix2f matrix;

    matrix <<   1, 1,
                1, 0;
    //MatrixPower<Matrix2f> mPow(matrix);
    Matrix2f result = matrix.pow(n);
    return result(0, 1);
    //return matrix(0,0);
}