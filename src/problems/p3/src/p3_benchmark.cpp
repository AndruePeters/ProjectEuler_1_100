#include <benchmark/benchmark.h>
#include <p3.h>

#define CUSTOM_RANGE_P3 Range(100, 1000000)

static void BM3_primegen_eratosthenes(benchmark::State& state)
{
    const unsigned limit = state.range(0);
    for (auto _ : state) {
        auto primes = primeSieveofEratosthenes(limit);
    }
} BENCHMARK(BM3_primegen_eratosthenes)->CUSTOM_RANGE_P3;

static void BM3_primegen_sundaram(benchmark::State& state)
{
    const unsigned limit = state.range(0);
    for (auto _ : state) {
        auto primes = primeSieveOfSundaram(limit);
    }
} BENCHMARK(BM3_primegen_sundaram)->CUSTOM_RANGE_P3;

static void BM3_primegen_atkin(benchmark::State& state)
{
    const unsigned limit = state.range(0);
    for (auto _ : state) {
        auto primes = primeSieveOfAtkin(limit);
    }
} BENCHMARK(BM3_primegen_atkin)->CUSTOM_RANGE_P3;
