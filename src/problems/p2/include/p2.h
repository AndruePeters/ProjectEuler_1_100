#ifndef P2_H
#define P2_H

#include <functional>

/**
 * @returns Nth Fibonacci number. 
 * @brief Uses naive recursion to solve.
 * @warning Insanely long compute times.
 */
unsigned fib_recursive(const unsigned n);

/**
 * @returns Nth Fibonacci number.
 * @brief Uses memoization and recursion.
 */
unsigned fib_memoization(const unsigned n);

/**
 * @returns Nth Fibonacci number.
 * @brief Uses memoization and reverses an if statement from regular function.
 */
unsigned fib_memoization_revIf(const unsigned n);

/**
 * @returns Nth Fibonacci number.
 * @brief Uses a naive loop.
 */
unsigned fib_loop(const unsigned n);

/**
 * @returns Nth Fibonacci number.
 * @brief Uses dynamic programming and a loop to calculate.
 */
unsigned fib_dynamic(const unsigned n);

/**
 * @returns Nth Fibonacci number.
 * @brief Uses golden ratio to calculated in constant time.
 * @warning Guaranteed to be close, but not correct.
 */
unsigned fib_golden_ratio(const unsigned n);

/**
 * @returns Nth fibonacci number.
 * @brief  Uses Eigen matrix exponentiation.
 */
unsigned fib_eigen_matrix_exp(const unsigned n);


/**
 * @returns Nth fibonacci number.
 * @brief  Uses an adaptation of fast matrix multiplication.
 */
unsigned fib_eigen_matrix_exp_fast(const unsigned n);


/**
 * @returns Sum of even fibonacci number using recursion + memoization.
 */
unsigned fib_sum_memoization(const unsigned fib_limit);

/**
 * @returns Sum of even fibonacci number using eigen matrix exponentiation.
 */
unsigned fib_sum_eigen_matrix(const unsigned fib_limit);

/**
 * @returns Sum of even fibonacci numbers using golden ratio to calculate
 * the nth fibonacci number. Each number is calculated in constant time.
 */
unsigned fib_sum_golden_ratio(const unsigned fib_limit);

/**
 * Calculates the sum of fibonacci numbers under fib_limit.
 * Accepts a function to calculate the nth fibonacci number. 
 */
unsigned fib_sum(const unsigned fib_limit, std::function<unsigned (unsigned)> fib_func);
#endif
