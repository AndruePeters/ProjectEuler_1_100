#ifndef P2_BENCHMARK_H
#define P2_BENCHMARK_H

#include <benchmark/benchmark.h>
#include <p2.h>


#define CUSTOM_RANGE_P2 Range(0, 30)

static void BM2_fib_constexpr_recursive(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_constexpr_recursive(fib);
    }
} BENCHMARK(BM2_fib_constexpr_recursive)->CUSTOM_RANGE_P2;

static void BM2_fib_recursive(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_recursive(fib);
    }
} BENCHMARK(BM2_fib_recursive)->CUSTOM_RANGE_P2;

static void BM2_fib_memoization(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_memoization(fib);
    }
} BENCHMARK(BM2_fib_memoization)->Range(8, 125000);

static void BM2_fib_memoization_revIf(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_memoization_revIf(fib);
    }
} BENCHMARK(BM2_fib_memoization_revIf)->Range(8, 125000);

static void BM2_fib_loop(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_loop(fib);
    }
} BENCHMARK(BM2_fib_loop)->Range(8, 125000);


static void BM2_fib_fast_matrix_exp(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_fast_matrix_exp(fib);
    }
} BENCHMARK(BM2_fib_fast_matrix_exp)->Range(8, 125000);

#endif