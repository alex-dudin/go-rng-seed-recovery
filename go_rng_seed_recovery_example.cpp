#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "go_rng_seed_recovery.hpp"

int main(int argc, char* argv[])
{
    const int values[] = { 60, 2, 9, 38, 82, 43, 35, 53, 14, 89 };
    
    std::atomic_uint32_t answer = 0;
    std::atomic_uint32_t total_seeds = 0;

    auto find_seed = [&](uint32_t start_seed, uint32_t length)
    {
        go_rng_seed_recovery rand(start_seed);

        uint32_t i = 0;
        for (; i < length && answer == 0; ++i)
        {
            unsigned matches = 0;
            for (int expected : values)
            {
                if (rand.int31n<100>() != expected)
                    break;

                matches++;
            }

            if (matches == std::size(values))
                answer = rand.current_seed();
            else
                rand.next_state();
        }
        total_seeds += i;
    };

    using clock = std::chrono::high_resolution_clock;
    const auto start = clock::now();

    std::vector<std::thread> threads;
    for (const auto& block : go_rng_seed_superblocks)
        threads.emplace_back(find_seed, block.start_seed, block.length);

    for (auto& t : threads)
        t.join();

    const double elapsed_sec = std::chrono::duration<double>(clock::now() - start).count();

    if (answer == 0)
    {
        std::cout << "Seed not found" << std::endl;
    }
    else
    { 
        std::cout << "Seed: " << answer << std::endl;
        std::cout << "Elapsed: " << elapsed_sec << " sec" << std::endl;
        if (elapsed_sec > 0)
            std::cout << "Speed: " << static_cast<uint64_t>(total_seeds / elapsed_sec) << " seed/sec" << std::endl;
    }
    return 0;
}
