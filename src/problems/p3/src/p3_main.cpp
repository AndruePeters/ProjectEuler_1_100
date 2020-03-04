#include <p3.h>
#include <spdlog/spdlog.h>

#include <iostream>

int main()
{
    auto primes = primeSieve(1000);

    auto primeFact = primeFactorization1(840);

    for (const auto pair: primeFact) {
        std::cout << "(" << pair.first << ',' << pair.second << ")\n";
    }

    for (const auto prime : primes ) {
        //std::cout << prime << ", ";
    }

    return 0;
}
