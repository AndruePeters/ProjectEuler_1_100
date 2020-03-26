///
/// \author Andrue Peters
/// \date 3/21/20
/// \brief Functions related to prime numbers.
///
#ifndef DRUE_PROJECT_EULER_PRIME_H_
#define DRUE_PROJECT_EULER_PRIME_H_

// STL includes
#include <algorithm>
#include <cmath>
#include <execution>
#include <vector>

// Boost includes
#include <boost/container/flat_map.hpp>

// Library includes
#include <gen_math.h>

namespace math {
///
/// \brief Generates a vector of prime numbers using the Sieve of Eratosthenes
/// Instead of generating all numbers and then removing multiples,
/// this method makes use of the realization that all primes are
/// in the forms n1 = 6q -1 and n2 = 6q + 1
/// 
/// If n1 is not divisible by 5, then it is prime
/// If n2 is not divisible by 7, then it is prime
/// 
template <class Integer>
std::vector<Integer> prime_sieve_eratosthenes(const Integer& limit)
{
    const Integer numPrimes = limit / static_cast<Integer>(std::log10(limit));
    std::vector<Integer> primes {Integer(2), Integer(3)};
    primes.reserve(numPrimes);

    const Integer five = 5;
    const Integer seven = 7;

    for (Integer i = 1; i < limit; ++i) {
        const Integer n1 = (6 * i) - 1;
        const Integer n2 = (6 * i) + 1;

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

///
/// \brief Generates a vector of prime numbers using the Sieve of Sundaram
///
template <class Integer>
std::vector<Integer> prime_sieve_sundaram(const Integer& limit)
{
    /// this sieve generates primes under 2n + 2
    /// the uesr wants all primes up to limit, so we'll calculate a new limit
    const Integer newLimit = static_cast<Integer>(std::floor((limit) / 2)) - 2;

    // estimate the number of primes to be generated
    const Integer numPrimes = limit / static_cast<Integer>(std::log10(limit));

    std::vector<Integer> sieveList (newLimit);
    sieveList.reserve(numPrimes);
    std::iota( sieveList.begin(), sieveList.end(), 1);

    //
    // Most implementation have an array of bools and then iterate
    // instead of setting a bool to true, set the value to 0
    // then the equation on that item will give (2 * 0) + 1 == 1, so it will still be correct 
    //
    for( Integer i = 1; i < newLimit; ++i) {
        for (Integer j = i; (i + j + 2*i*j) < newLimit; ++j) {
            sieveList[i + j + 2*i*j -1 ] = 0;
        }
    }

    /// Multiply every element, n, 2 and add 1
    std::transform(std::execution::seq, sieveList.begin(), sieveList.end(), sieveList.begin(),
        [] (const Integer n) { return (n * 2) + 1; });

    /// remove all extra 0's from the list
    sieveList.erase(std::remove_if(std::execution::seq, sieveList.begin(), sieveList.end(), 
        [](const Integer n) { return n == 0; }),
        sieveList.end()
    );
    
    /// need to add 2 back to the sieve
    sieveList.push_back(2);
    return sieveList;
}

///
/// \brief Generates a vector of prime numbers using the Sieve of Atkin
///
template <class Integer>
std::vector<Integer> prime_sieve_atkin(const Integer& limit)
{
    const Integer numPrimes = limit / static_cast<Integer>(std::log10(limit));

    std::vector<Integer> results {2, 3, 5};
    results.reserve(numPrimes);
    std::vector<bool>   primeMarkings (limit, false); // false means composite, true means prime

    const Integer two {2};
    for (Integer i = 1; math::pow(i, two) < limit; ++i) {
        for (Integer j = 1; math::pow(j, two) < limit; ++j) {
            const Integer i2 = math::pow(i, two);
            const Integer j2 = math::pow(j, two);

            const Integer n = (4 * i2) + j2;
            const Integer n2 = (3 * i2) + j2;
            const Integer n3 = (3 * i2) + j2;
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

    for (Integer i = 5; math::pow(i, two) < limit; ++i) {
        if (primeMarkings[i]) {
            for (Integer j = std::pow(i, two); j < limit; j += std::pow(i, two)) {
                primeMarkings[j] = false;
            }
        }
    }

    for (Integer i = 5; i < limit; ++i) {
        if (primeMarkings[i]) {
            results.push_back(i);
        }
    }

    return results;
}

///
/// \brief Factorizes a number and returns a map of the prime factors and their occurrences
///
/// There are more optimizations that can take place.
/// For example, take some number, n
///    Initially, only use numbers up to sqrt(n) (this is already being done when the prime vector is generated)
///    Once you find some factor, k, you essentially have a new number that is equal to n / k
///    For this "new" factor, you only have to check up to sqrt(n / k)
///
/// This method is fast enough for the time being, but I will probably end up optimizing this to death for fun later
template <class Integer>
boost::container::flat_map<Integer, Integer> prime_factorization(const Integer& factorize)
{
    /// this struct just makes things easier than a tuple, and gives more meaning than std::pair
    struct PrimePair {Integer prime; Integer occurences; };

    // generate the limit of primes to produce => to factor a number, you only need up to sqrt( number_to_factorize )
    const Integer limit = std::floor(std::sqrt(factorize));
    const auto primes = prime_sieve_eratosthenes( limit ); ///< get the actual primes
    boost::container::flat_map<Integer, Integer> primePairs;
    
    Integer n = factorize;
    
    for (const auto prime: primes) {
        while ((n % prime) == 0) {
            n = n / prime;
            ++primePairs[prime];
        }
    }

    return primePairs;
}

} // namespace math

#endif