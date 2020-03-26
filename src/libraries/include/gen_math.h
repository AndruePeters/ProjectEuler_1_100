///
/// \author Andrue Peters
/// \date 3/21/20
/// \brief Miscellaneous math related functions I don't know how to categorize.
///
#ifndef DRUE_PROJECT_EULER_GENMATH_H_
#define DRUE_PROJECT_EULER_GENMATH_H_

namespace math {
///
/// \brief Constant time evaluation of the sum of integers from 1 to n
/// Evaluation of the series: E[k=1 to n] (k) 
///
/// Assumptions: n > 1
template <class Integer> constexpr
Integer  consecutive_sum(const Integer& n)
{
    return static_cast<Integer>( (0.5) * n * (n + 1));
}

///
/// \brief Calculates the some number, n, raises to a power, p => n^p
/// There are probably better solutions, but this can be calculated at compile-time.
template <class Integer> 
Integer pow(const Integer& n, const Integer& p) 
{
    Integer result = n;
    for (Integer i = 0; i < p-1; ++i) {
        result = result * n;
    }
    return result;
}

 ///
 /// \brief  Calculates the nth Fibonacci number
 /// Fast and efficient implementation to generate Fibonacci number
 ///
 /// | 1 1 | ^ n = | F(n+1)  Fn     |
 /// | 1 0 |       | F(n)    F(n-1) |
 ///
 /// This method uses 1 less calculation than needed by returning the top left element
 /// This means for F(n), I only need to exponentiate the matrix (n - 1) times
 ///
 /// Assumptions: n > 0
unsigned fibonacci(const unsigned n);

///
/// \brief A different way of calculating the nth Fibonacci number
/// Uses boost::flat_map to cache results via memoization
/// I've kept this method mostly for benchmarking and a reminder for the future.
unsigned fibonacci_memoization(const unsigned n);


} // namespace math

#endif