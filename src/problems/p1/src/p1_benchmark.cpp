#include <benchmark/benchmark.h>

#include <p1.h>

#define CUSTOM_RANGE Range(1000, 1000<<20)

static void BM1_p1_loop(benchmark::State& state) 
{
    const int upperBound = static_cast<int>(state.range(0));
    for (auto _ : state) {
        p1_loop(upperBound);
    }
}
BENCHMARK(BM1_p1_loop)->CUSTOM_RANGE;

static void BM1_p1_loop_constexpr(benchmark::State& state)
{
    const int upperBound = static_cast<int>(state.range(0));
    for (auto _ : state) {
        int i = p1_loop_constexpr(upperBound);
        (void)i;
    }
}
BENCHMARK(BM1_p1_loop_constexpr)->CUSTOM_RANGE;

static void BM1_p1_rawloop_vector(benchmark::State& state)
{
    auto vector = generateVector(static_cast<int>(state.range(0)));
    for (auto _ : state) {
        p1_rawloop_vector(vector);
    }
}
BENCHMARK(BM1_p1_rawloop_vector)->CUSTOM_RANGE;

static void BM1_p1_partial_sum_formula(benchmark::State& state)
{
    const int upperBound = static_cast<int>(state.range(0));
    for (auto _ : state) {
        p1_partial_sum_formula(upperBound);
    }
}
BENCHMARK(BM1_p1_partial_sum_formula)->CUSTOM_RANGE;
