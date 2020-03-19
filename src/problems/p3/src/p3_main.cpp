#include <p3.h>
#include <spdlog/spdlog.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <set>

#include <boost/container/flat_map.hpp>

int main()
{
    unsigned long factorize = 600851475143;
    auto factorMap = primeFactorization1(factorize);

    const auto greatestFactor = std::max_element(factorMap.begin(), factorMap.end(), 
    [](const std::pair<unsigned, unsigned>& p1, const std::pair<unsigned, unsigned>& p2) {
        return p1.first > p2.second;
    });

    std::cout << "Greatest factor: " << greatestFactor->first << " appeared " << greatestFactor->second << " times.\n";
    return 0;
}
