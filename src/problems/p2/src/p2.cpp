#include "p2.h"

#include <boost/container/flat_map.hpp>

int fib_recursive(const unsigned n)
{
    if (n <= 1) return 1;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

unsigned fib_memoization(const unsigned n)
{
    static boost::container::flat_map<unsigned, unsigned> mem_map;

    if (n <= 1) return 1;
    auto it = mem_map.find(n);
    if (it == mem_map.end()) {
        return mem_map[n] = fib_memoization(n - 1) + fib_memoization(n - 2);
    } else {
        return it->second;
    }
}