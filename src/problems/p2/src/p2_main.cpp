///
/// \author Andrue Peters
/// \date 3/25/20
/// 
/// \brief Implementation for Problem 2
///

#include <iostream>

// Problem 2 includes
#include <p2.h>


int main()
{
    const unsigned fib_limit = 4'000'000;
    std::cout << "fibonacci: " << even_fibonacci_sum(fib_limit) << std::endl;
    return 0;
}
