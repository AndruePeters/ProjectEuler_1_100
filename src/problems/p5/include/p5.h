///
/// \author Andrue Peters
/// \date 4/4/20
///
/// \brief Solves ProjectEuler Problem 5
///

#ifndef P5_H
#define P5_H

#include <cmath>

#include <algorithm>
#include <numeric>
#include <functional>

#include <gen_math.h>
#include <prime.h>

#include <iostream>

template <class Integer>
Integer least_common_multiple(const Integer upper_limit)
{
    // sorted list of primes
    auto primes = math::prime_sieve_atkin(upper_limit);
    std::sort(primes.begin(), primes.end());
    for( const auto val : primes) {
        std::cout << val << ", ";
    }
    // only need to look up to sqrt(upper_limit)
    auto sqrt_limit = std::upper_bound(primes.begin(), primes.end(), std::floor(std::sqrt(upper_limit)));
    std::cout << "square root limit: " << *sqrt_limit << std::endl;

    // the maximum number of times a prime will occur and be less than upper_limit is log base(prime) (upper_limit)
    // go ahead and multiply these primes by the highest degree that occurs
    std::transform (primes.begin(), sqrt_limit, primes.begin(), 
        [upper_limit]( Integer& n) {
            auto log = std::floor(math::log_b(n, upper_limit));
            return std::pow(n, static_cast<Integer>(log));
            //return n * static_cast<Integer>(log);
        }
    );


    // multiply all of the numbers together to find the LCM
    return std::reduce(primes.begin(), primes.end(), static_cast<Integer>(1), std::multiplies<>{} );
} 

template <class Integer>
Integer largest_prime_multiple_in_consecutive_range(const Integer p, const Integer range)
{
    Integer log = static_cast<Integer>(math::log_b(p, range));
    return p * log;
}

#endif
