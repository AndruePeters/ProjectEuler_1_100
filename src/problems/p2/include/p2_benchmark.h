#ifndef P2_BENCHMARK_H
#define P2_BENCHMARK_H

#include <benchmark/benchmark.h>
#include <p2.h>


#define CUSTOM_RANGE_P2 Range(0, 30)


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

static void BM2_fib_golden_ratio(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_golden_ratio(fib);
    }
} BENCHMARK(BM2_fib_golden_ratio)->Range(8, 125000);

static void BM2_fib_dynamic(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_dynamic(fib);
    }
} BENCHMARK(BM2_fib_dynamic)->Range(8, 125000);


static void BM2_fib_eigen_matrix_exp(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_eigen_matrix_exp(fib);
    }
} BENCHMARK(BM2_fib_eigen_matrix_exp)->Range(8, 125000);

static void BM2_fib_eigen_matrix_exp_fast(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_eigen_matrix_exp_fast(fib);
    }
} BENCHMARK(BM2_fib_eigen_matrix_exp_fast)->Range(8, 125000);


static void BM2_fib_sum_memoization(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_sum_memoization(fib);
    }
} BENCHMARK(BM2_fib_sum_memoization)->Range(8, 125000);

static void BM2_fib_sum_eigen_matrix(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_sum_eigen_matrix(fib);
    }
} BENCHMARK(BM2_fib_sum_eigen_matrix)->Range(8, 125000);

static void BM2_fib_sum_golden_ratio(benchmark::State& state)
{
    const unsigned fib = state.range(0);
    for (auto _ : state) {
        fib_sum_golden_ratio(fib);
    }
} BENCHMARK(BM2_fib_sum_golden_ratio)->Range(8, 125000);

#endif
