#ifndef P2_H
#define P2_H


constexpr int fib_constexpr_recursive(const unsigned n) 
{
    if ( n <= 1) return 1;
    return  fib_constexpr_recursive(n - 1) + fib_constexpr_recursive(n - 2);
}

int fib_recursive(const unsigned n);

unsigned fib_memoization(const unsigned n);

#endif