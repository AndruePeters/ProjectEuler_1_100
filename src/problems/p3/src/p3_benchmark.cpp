///
/// \author Andrue Peters
/// \date 3/25/20
///

#include <p3.h>

// include Google Benchmark
#include <benchmark/benchmark.h>

static void Problem3(benchmark::State& state)
{
    const unsigned long factorize = 600851475143;
    for (auto _ : state) {
        largest_prime_factor(factorize);
    }
} BENCHMARK(Problem3);

