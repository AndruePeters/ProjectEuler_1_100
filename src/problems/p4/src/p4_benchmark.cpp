///
/// \author Andrue Peters
/// \date 4/2/20
///

#include <p4.h>

// include Google Benchmark
#include <benchmark/benchmark.h>

static void Problem4(benchmark::State& state)
{
    const unsigned digit_length = 3;
    for (auto _ : state) {
        benchmark::DoNotOptimize(largest_palindrome(digit_length));
    }
} BENCHMARK(Problem4);

