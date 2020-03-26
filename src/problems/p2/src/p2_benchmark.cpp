///
/// \author Andrue Peters
/// \date 3/25/20
///

#include <p2.h>

// include Google Benchmark
#include <benchmark/benchmark.h>

///
/// Benchmark for Problem 2 of Project Euler
///
static void Problem2(benchmark::State& state)
{
    const unsigned fib_limit = 4'000'000;
    for (auto _ : state) {
        even_fibonacci_sum(fib_limit);
    }
} BENCHMARK(Problem2);

