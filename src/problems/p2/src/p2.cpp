///
/// \author Andrue Peters
/// \date 3/25/20
/// 
/// \brief Implementation for Problem 2
///


#include <p2.h>
#include <gen_math.h>


///
/// \brief Returns the sum of all even fibonacci numbers
/// Makes use of the realization that every 3rd fibonacci number is even
///
unsigned even_fibonacci_sum(const unsigned fib_limit)
{
    // first even fibonacci number is 2, so let's just start with that
    unsigned fib = 2;

    // every even fib number has index multiple of 3, but we already started with fib(3) = 2,
    // so jump to the next even index
    unsigned fibIndex = 6;

    // running sum
    unsigned sum = 0;

    // loop is setup so that it adds the previous fib to the sum, and then calculate
    while (fib < fib_limit ) {
        sum += fib;
        fib = math::fibonacci(fibIndex);
        fibIndex += 3;
    }
    return sum;
}