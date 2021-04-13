#pragma once

#include <cstdint>
#include <limits>
#include <random>
#include <stdexcept>

struct go_rng_seed_block
{
    uint32_t start_seed;
    uint32_t length;
};

extern const go_rng_seed_block go_rng_seed_superblocks[4];

extern const int64_t rng_cooked[607];

class go_rng_seed_recovery
{
public:
    explicit go_rng_seed_recovery(uint32_t raw_seed)
    {
        set_state(raw_seed);
    }

    uint32_t current_seed() const
    {
        return seeds[offset];
    }

    void set_state(uint32_t raw_seed)
    {
        offset = 0;
        rand_state = raw_seed;
        vec0_ptr = vec0;

        reset_state();
        
        for (int i = 0; i < RNG_LEN; ++i)
        {
            seeds[i] = rand_state;
            int64_t u = int64_t(next_rand()) << 40;
            u ^= int64_t(next_rand()) << 20;
            u ^= int64_t(next_rand());
            vec0[i] = u;
            vec0[i + RNG_LEN] = u;
        }
    }

    void next_state()
    {
        reset_state();

        const int i = offset++;
        if (offset == RNG_LEN)
            offset = 0;

        seeds[i] = rand_state;
        int64_t u = int64_t(next_rand()) << 40;
        u ^= int64_t(next_rand()) << 20;
        u ^= int64_t(next_rand());
        vec0[i] = u;
        vec0[i + RNG_LEN] = u;

        vec0_ptr = vec0 + offset;
    }

    void reset_state()
    {
        tap = RNG_LEN - 1;
        feed = RNG_LEN - RNG_TAP - 1;
        count = 0;
    }

    int32_t int31()
    {
        return static_cast<int32_t>(int63() >> 32);
    }

    int64_t int63()
    {
        return static_cast<int64_t>(uint64() & RNG_MASK);
    }

    int32_t int31n(int32_t n)
    {
        if (n <= 0)
            throw std::invalid_argument("int31n: value is less than or equal to zero");

        if ((n & (n - 1)) == 0)
            return int31() & (n - 1);

        const int32_t max = static_cast<int32_t>((1u << 31) - 1 - (1u << 31) % static_cast<uint32_t>(n));
        int32_t v = int31();
        while (v > max)
        {
            v = int31();
        }
        return v % n;
    }
    
    template <uint32_t n>
    int32_t int31n()
    {
        static_assert(n > 0 && n <= std::numeric_limits<int32_t>::max());

        if ((n & (n - 1)) == 0)
            return int31() & (n - 1);

        constexpr auto max = (1u << 31) - 1 - (1u << 31) % n;
        auto v = static_cast<uint32_t>((uint64() & RNG_MASK) >> 32);
        while (v > max)
        {
            v = static_cast<uint32_t>(int31());
        }
        return static_cast<int32_t>(v % n);
    }
    
    int64_t int63n(int64_t n)
    {
        if (n <= 0)
            throw std::invalid_argument("int63n: value is less than or equal to zero");

        if ((n & (n - 1)) == 0)
            return int63() & (n - 1);

        const int64_t max = static_cast<int64_t>((UINT64_C(1) << 63) - 1 - (UINT64_C(1) << 63) % static_cast<uint64_t>(n));
        int64_t v = int63();
        while (v > max)
        {
            v = int63();
        }
        return v % n;
    }

    template <uint64_t n>
    int64_t int63n()
    {
        static_assert(n > 0 && n <= std::numeric_limits<int64_t>::max());

        if ((n & (n - 1)) == 0)
            return int63() & (n - 1);

        constexpr auto max = (UINT64_C(1) << 63) - 1 - (UINT64_C(1) << 63) % n;
        auto v = uint64() & RNG_MASK;
        while (v > max)
        {
            v = uint64() & RNG_MASK;
        }
        return static_cast<int64_t>(v % n);
    }

    uint32_t uint32()
    {
        return static_cast<uint32_t>(int63() >> 31);
    }

    uint64_t uint64()
    {
        const auto feed_prev = feed;
        int64_t x;
        if (count < RNG_TAP)
        {
            x = (vec0_ptr[feed] ^ rng_cooked[feed]) + (vec0_ptr[tap] ^ rng_cooked[tap]);

            count++;
            tap--;
            feed--;
        }
        else
        {
            if (count < RNG_LEN)
            {
                x = (vec0_ptr[feed] ^ rng_cooked[feed]) + vec1[tap];
                count++;
            }
            else
            {
                x = vec1[feed] + vec1[tap];
            }

            tap--;
            if (tap < 0)
                tap += RNG_LEN;

            feed--;
            if (feed < 0)
                feed += RNG_LEN;
        }
        vec1[feed_prev] = x;
        return static_cast<uint64_t>(x);
    }

    uint64_t peek_uint64()
    {
        int64_t x;
        if (count < RNG_TAP)
        {
            x = (vec0_ptr[feed] ^ rng_cooked[feed]) + (vec0_ptr[tap] ^ rng_cooked[tap]);
        }
        else
        {
            if (count < RNG_LEN)
            {
                x = (vec0_ptr[feed] ^ rng_cooked[feed]) + vec1[tap];
            }
            else
            {
                x = vec1[feed] + vec1[tap];
            }
        }
        return static_cast<uint64_t>(x);
    }

    void peek_uint64_array(uint64_t* result, size_t n)
    {
        if (n > 100)
            throw std::invalid_argument("peek_uint64_array: value is out of range [0,100]");

        const auto original_feed = feed;
        const auto original_tap = tap;
        const auto original_count = count;
        for (size_t i = 0; i < n; ++i)
        {
            int64_t x;
            if (count < RNG_TAP)
            {
                x = (vec0_ptr[feed] ^ rng_cooked[feed]) + (vec0_ptr[tap] ^ rng_cooked[tap]);
            }
            else
            {
                if (count < RNG_LEN)
                {
                    x = (vec0_ptr[feed] ^ rng_cooked[feed]) + vec1[tap];
                }
                else
                {
                    x = vec1[feed] + vec1[tap];
                }
            }

            tap--;
            if (tap < 0)
                tap += RNG_LEN;

            feed--;
            if (feed < 0)
                feed += RNG_LEN;

            count++;

            result[i] = static_cast<uint64_t>(x);
        }
        feed = original_feed;
        tap = original_tap;
        count = original_count;
    }

    static uint32_t get_raw_seed(int32_t seed);
    static int32_t recover_normal_seed(uint32_t raw_seed);

private:
    static constexpr int RNG_LEN = 607;
    static constexpr int RNG_TAP = 273;
    static constexpr uint64_t RNG_MASK = (UINT64_C(1) << 63) - 1;

    int tap;
    int feed;
    int64_t vec0[RNG_LEN * 2];
    int64_t vec1[RNG_LEN];
    int64_t* vec0_ptr;
    uint32_t seeds[RNG_LEN];
    int offset;
    uint32_t rand_state;
    int count;

    uint32_t next_rand()
    {
        const uint64_t product = (uint64_t)rand_state * 48271;
        const uint32_t x = (product & 0x7fffffff) + (product >> 31);
        return rand_state = (x & 0x7fffffff) + (x >> 31);
    }
};
