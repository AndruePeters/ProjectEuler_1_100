#ifndef P3_H
#define P3_H

#include <cmath>
#include <map>
#include <vector>
/**
 * Sieve of Eratosthenes
 * Instead of generating all numbers and then removing multiples,
 * this method makes use of the realization that all primes are
 * in the forms n1 = 6q -1 and n2 = 6q + 1
 * 
 * If n1 is not divisible by 5, then it is prime
 * If n2 is not divisible by 7, then it is prime
 * 
 */
template <class Number>
std::vector<Number> primeSieve(const Number& limit)
{
    // const Number numPrimes = limit / std::log10(limit);
    // vector.reserve(numPrimes); // might have performance increase
    std::vector<Number> primes {2, 3};

    for (Number i = 1; i < limit; ++i) {
        const Number n1 = (6 * i) - 1;
        const Number n2 = (6 * i) + 1;

        // if rem1 is 0 then it's a multiple of 5 and not a prime
        // 5 == 6 - 1
        if ( (n1 % 5) != 0) {
            primes.push_back(n1);
        }

        // if rem2 is 0 then it's a multiple of 7 and not a prime
        // 7 == 6 + 1
        if ( (n2 % 7) != 0) {
            primes.push_back(n2);
        }
    }

    return primes;
}


template <class Number>
std::map<Number, Number> primeFactorization1(const Number& factorize)
{
    struct PrimePair {Number prime; Number occurences; };

    const auto primes = primeSieve( std::sqrt(factorize) );
    std::map<Number, Number> primePairs;
    
    Number n = factorize;
    

    for (const auto prime: primes) {
        while (static_cast<Number>(prime % n) == 0) {
            n = n / prime;
            ++primePairs[prime];
        }
    }

    return primePairs;
}


#endif
