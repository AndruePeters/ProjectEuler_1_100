///
/// \author Andrue Peters
/// \date 3/25/20
///
/// \brief Solves ProjectEuler Problem 3
///

#include <iostream>

#include <p3.h>

int main()
{
    const unsigned long factorize = 600851475143;
    std::cout << "Greatest factor: " << largest_prime_factor(factorize) << '\n';
    return 0;
}
