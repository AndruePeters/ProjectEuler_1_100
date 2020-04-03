///
/// \author Andrue Peters
/// \date 3/25/20
///
/// Implementation for problem 3


#include <p3.h>
#include <prime.h>

#include <algorithm>

#include <boost/container/flat_map.hpp>
///
/// \brief Returns the largest factor of \p factorize
///
unsigned long largest_prime_factor(unsigned long factorize)
{
    using ul_t = unsigned long long;

    const auto factorMap = math::prime_factorization(factorize);
    const auto greatestFactor = std::max_element(factorMap.cbegin(), factorMap.cend(),
    [](const std::pair<ul_t, ul_t>& p1, const std::pair<ul_t, ul_t>& p2) {
        return p1.first < p2.first;
    });

    return greatestFactor->first;
}
