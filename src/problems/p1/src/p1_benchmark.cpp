///
/// \author Andrue Peters
/// \date 3/25/20
///
/// \brief Benchmarks for Project Euler Problem 1

#include <p1.h>

// include Google Benchmark
#include <benchmark/benchmark.h>

static void Problem1(benchmark::State& state) 
{
    const int upperBound = 1000;
    for (auto _ : state) {
        p1_partial_sum_formula(upperBound);
    }
}
BENCHMARK(Problem1);

