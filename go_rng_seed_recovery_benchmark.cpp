#include <benchmark/benchmark.h>
#include "go_rng_seed_recovery.hpp"

static void go_rng_seed_recovery__init(benchmark::State& state)
{
    unsigned i = 1;
    for (auto _ : state)
    {
        go_rng_seed_recovery rand(i++);
        benchmark::DoNotOptimize(rand.current_seed());
    }
}
BENCHMARK(go_rng_seed_recovery__init);

static void go_rng_seed_recovery__set_state(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    unsigned i = 1;
    for (auto _ : state)
    {
        rand.set_state(i++);
    }
}
BENCHMARK(go_rng_seed_recovery__set_state);

static void go_rng_seed_recovery__next_state(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.next_state();
    }
}
BENCHMARK(go_rng_seed_recovery__next_state);

static void go_rng_seed_recovery__reset_state(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.reset_state();
    }
}
BENCHMARK(go_rng_seed_recovery__reset_state);

static void go_rng_seed_recovery__int31(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.int31();
    }
}
BENCHMARK(go_rng_seed_recovery__int31);

static void go_rng_seed_recovery__int63(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.int63();
    }
}
BENCHMARK(go_rng_seed_recovery__int63);

static void go_rng_seed_recovery__int31n(benchmark::State& state)
{
    const int n = static_cast<int>(state.range(0));
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.int31n(n);
    }
}
BENCHMARK(go_rng_seed_recovery__int31n)->Arg(10)->Arg(3500);

static void go_rng_seed_recovery__int31n_10(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.int31n<10>();
    }
}
BENCHMARK(go_rng_seed_recovery__int31n_10);

static void go_rng_seed_recovery__int31n_3500(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.int31n<3500>();
    }
}
BENCHMARK(go_rng_seed_recovery__int31n_3500);

static void go_rng_seed_recovery__int63n(benchmark::State& state)
{
    const auto n = state.range(0);
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.int63n(n);
    }
}
BENCHMARK(go_rng_seed_recovery__int63n)->Arg(10)->Arg(3500);

static void go_rng_seed_recovery__int63n_10(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.int63n<10>();
    }
}
BENCHMARK(go_rng_seed_recovery__int63n_10);

static void go_rng_seed_recovery__int63n_3500(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.int63n<3500>();
    }
}
BENCHMARK(go_rng_seed_recovery__int63n_3500);

static void go_rng_seed_recovery__uint32(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.uint32();
    }
}
BENCHMARK(go_rng_seed_recovery__uint32);

static void go_rng_seed_recovery__uint64(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        rand.uint64();
    }
}
BENCHMARK(go_rng_seed_recovery__uint64);

static void go_rng_seed_recovery__peek_uint64(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(rand.peek_uint64());
    }
}
BENCHMARK(go_rng_seed_recovery__peek_uint64);

static void go_rng_seed_recovery__peek_uint64_array3(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    uint64_t values[3];
    for (auto _ : state)
    {
        rand.peek_uint64_array(values, std::size(values));
        benchmark::DoNotOptimize(values[0]);
    }
}
BENCHMARK(go_rng_seed_recovery__peek_uint64_array3);

static void go_rng_seed_recovery__peek_uint64_array10(benchmark::State& state)
{
    go_rng_seed_recovery rand(1);
    uint64_t values[10];
    for (auto _ : state)
    {
        rand.peek_uint64_array(values, std::size(values));
        benchmark::DoNotOptimize(values[0]);
    }
}
BENCHMARK(go_rng_seed_recovery__peek_uint64_array10);

static void go_rng_seed_recovery__generate_map(benchmark::State& state)
{
    for (auto _ : state)
    {
        go_rng_seed_recovery rand(1);
        for (int i = 0; i < 490'000; ++i)
        {
            rand.int31n<3500>();
            rand.int31n<3500>();
            rand.int31n<10>();
        }
    }
}
BENCHMARK(go_rng_seed_recovery__generate_map);

static void go_rng_seed_recovery__minstd_rand(benchmark::State& state)
{
    unsigned x = 0;
    std::minstd_rand rand(1);
    for (auto _ : state)
    {
        x = rand();
        x = rand();
        x = rand();
    }
    benchmark::DoNotOptimize(x);
}
BENCHMARK(go_rng_seed_recovery__minstd_rand);

inline int seedrand(int x)
{
    constexpr int A = 48271;
    constexpr int Q = 44488;
    constexpr int R = 3399;

    const int hi = x / Q;
    const int lo = x % Q;

    x = A * lo - R * hi;

    if (x < 0)
        x += 2147483647;

    return x;
}

static void go_rng_seed_recovery__seedrand(benchmark::State& state)
{
    int x = 1;
    for (auto _ : state)
    {
        x = seedrand(x);
        x = seedrand(x);
        x = seedrand(x);
    }
    benchmark::DoNotOptimize(x);
}
BENCHMARK(go_rng_seed_recovery__seedrand);

inline uint32_t lcg_parkmiller(uint32_t x)
{
    uint64_t product = (uint64_t)x * 48271;
    x = (product & 0x7fffffff) + (product >> 31);
    return (x & 0x7fffffff) + (x >> 31);
}

static void go_rng_seed_recovery__lcg_parkmiller(benchmark::State& state)
{
    uint32_t x = 1;
    for (auto _ : state)
    {
        x = lcg_parkmiller(x);
        x = lcg_parkmiller(x);
        x = lcg_parkmiller(x);
    }
    benchmark::DoNotOptimize(x);
}
BENCHMARK(go_rng_seed_recovery__lcg_parkmiller);

BENCHMARK_MAIN();
