#ifndef P3_H
#define P3_H

#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <vector>
#include <iostream>
#include <execution>

#include <boost/container/flat_map.hpp>

namespace drue {
    template <class Number>
    Number pow(const Number& n, const Number& times) 
    {
        Number result = n;
        for (Number i = 0; i < times-1; ++i) {
            result = result * n;
        }
        return result;
    }
}


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
    const Number numPrimes = limit / static_cast<Number>(std::log10(limit));
    std::vector<Number> primes {Number(2), Number(3)};
    primes.reserve(numPrimes);

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
    const Number numPrimes = limit / static_cast<Number>(std::log10(limit));

    
    std::vector<Number> sieveList (newLimit);
    sieveList.reserve(numPrimes);
    std::iota( sieveList.begin(), sieveList.end(), 1);


    //
    // Most implementation have an array of bools and then iterate
    // instead of setting a bool to true, set the value to 0
    // then the equation on that item will give (2 * 0) + 1 == 1, so it will still be correct 
    //
    for( Number i = 1; i < newLimit; ++i) {
        for (Number j = i; (i + j + 2*i*j) < newLimit; ++j) {
            sieveList[i + j + 2*i*j -1 ] = 0;
        }
    }

    std::transform(std::execution::seq, sieveList.begin(), sieveList.end(), sieveList.begin(),
        [] (Number n) { return (n * 2) + 1; });

    


    sieveList.erase(std::remove_if(std::execution::seq, sieveList.begin(), sieveList.end(), 
        [](Number n) { return n == 0; }),
        sieveList.end()
    );
    
    sieveList.push_back(2);
    return sieveList;
}

template <class Number>
std::vector<Number> primeSieveOfAtkin(const Number& limit)
{
    const Number numPrimes = limit / static_cast<Number>(std::log10(limit));

    std::vector<Number> results {2, 3, 5};
    results.reserve(numPrimes);
    std::vector<bool>   primeMarkings (limit, false); // false means composite, true means prime

    const Number two {2};
    for (Number i = 1; drue::pow(i, two) < limit; ++i) {
        for (Number j = 1; drue::pow(j, two) < limit; ++j) {
            const Number i2 = drue::pow(i, two);
            const Number j2 = drue::pow(j, two);

            const Number n = (4 * i2) + j2;
            const Number n2 = (3 * i2) + j2;
            const Number n3 = (3 * i2) + j2;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
                primeMarkings[n] = !primeMarkings[n];
            }

            if (n2 <= limit && n2 %12 == 7) {
                primeMarkings[n2] = !primeMarkings[n2];
            }

            if (i > j && n3 <= limit && n3 % 12 == 11) {
                primeMarkings[n3] = !primeMarkings[n3];
            }
        }
    }

    for (Number i = 5; drue::pow(i, two) < limit; ++i) {
        if (primeMarkings[i]) {
            for (Number j = std::pow(i, two); j < limit; j += std::pow(i, two)) {
                primeMarkings[j] = false;
            }
        }
    }

    for (Number i = 5; i < limit; ++i) {
        if (primeMarkings[i]) {
            results.push_back(i);
        }
    }

    return results;
}

template <class Number>
boost::container::flat_map<Number, Number> primeFactorization1(const Number& factorize)
{
    struct PrimePair {Number prime; Number occurences; };
    

    const Number limit = std::floor(std::sqrt(factorize));
    const auto primes = primeSieveofEratosthenes( limit );
    boost::container::flat_map<Number, Number> primePairs;
    
    Number n = factorize;
    
    for (const auto prime: primes) {
        while ((n % prime) == 0) {
            n = n / prime;
            ++primePairs[prime];
        }
    }

    return primePairs;
}


#endif
