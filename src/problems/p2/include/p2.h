#ifndef P2_H
#define P2_H


constexpr unsigned fib_constexpr_recursive(const unsigned n) 
{
    if ( n <= 1) return 1;
    return  fib_constexpr_recursive(n - 1) + fib_constexpr_recursive(n - 2);
}

unsigned fib_recursive(const unsigned n);

unsigned fib_memoization(const unsigned n);

unsigned fib_memoization_revIf(const unsigned n);

unsigned fib_loop(const unsigned n);

unsigned fib_fast_matrix_exp(const unsigned n);
unsigned fib_fast_matrix_exp(const unsigned n, const unsigned a, const unsigned b);

#endif