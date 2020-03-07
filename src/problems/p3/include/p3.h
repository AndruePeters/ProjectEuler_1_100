#ifndef P3_H
#define P3_H

#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <vector>

#include <iostream>
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
std::vector<Number> primeSieveofEratosthenes(const Number& limit)
{
    // const Number numPrimes = limit / std::log10(limit);
    // vector.reserve(numPrimes); // might have performance increase
    std::vector<Number> primes {Number(2), Number(3)};

    const Number five = 5;
    const Number seven = 7;

    for (Number i = 1; i < limit; ++i) {
        const Number n1 = (6 * i) - 1;
        const Number n2 = (6 * i) + 1;


        // if rem1 is 0 then it's a multiple of 5 and not a prime
        // 5 == 6 - 1
        if ( (n1 % five) != 0 && (n1 % seven) != 0) {
            primes.push_back(n1);
        }

        // if rem2 is 0 then it's a multiple of 7 and not a prime
        // 7 == 6 + 1
        if ( (n2 % seven) != 0 && (n2 % five) != 0) {
            primes.push_back(n2);
        }
    }

    return primes;
}

template <class Number>
std::vector<Number> primeSieveOfSundaram(const Number& limit)
{
    const Number newLimit = static_cast<Number>(std::floor((limit) / 2)) - 2;
    
    std::vector<Number> list (newLimit);
    std::iota(list.begin(), list.end(), 1);


    //
    // Most implementation have an array of bools and then iterate
    // instead of setting a bool to true, set the value to 0
    // then the equation on that item will give (2 * 0) + 1 == 1, so it will still be correct 
    //
    for( Number i = 1; i < newLimit; ++i) {
        for (Number j = i; (i + j + 2*i*j) < newLimit; ++j) {
            std::cout << "(" << i << "," << j << "): " << i + j + 2*i*j << std::endl;
            list[i + j + 2*i*j -1 ] = 0;
        }
    }

    list.erase(std::remove_if(list.begin(), list.end(), 
        [](Number n) {
            return n == 0;
        }),
        list.end()
    );

    std::transform(list.begin(), list.end(), list.begin(),
        [] (Number n) {
            return (n * 2) + 1;
        });

    list.push_back(2);
    return list;
}


template <class Number>
std::map<Number, Number> primeFactorization1(const Number& factorize)
{
    struct PrimePair {Number prime; Number occurences; };

    const Number limit = std::floor(std::sqrt(factorize));
    const auto primes = primeSieveofEratosthenes( limit );
    std::map<Number, Number> primePairs;
    
    Number n = factorize;
    
    for (const auto prime: primes) {
        std::cout << "prime(" << prime << "), ";
        while ((n % prime) == 0) {
            n = n / prime;
            ++primePairs[prime];
        }
        std::cout << '\n';
    }

    return primePairs;
}


#endif
