#include <gtest/gtest.h>
#include "go_rng_seed_recovery.hpp"

TEST(go_rng_seed_recovery, int31)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    ASSERT_EQ(rand.int31(), INT32_C(2029793274));
    ASSERT_EQ(rand.int31(), INT32_C(526058514));
    ASSERT_EQ(rand.int31(), INT32_C(1408655353));
    ASSERT_EQ(rand.int31(), INT32_C(116702506));
    ASSERT_EQ(rand.int31(), INT32_C(789387515));
    ASSERT_EQ(rand.int31(), INT32_C(621654496));
    ASSERT_EQ(rand.int31(), INT32_C(413258767));
    ASSERT_EQ(rand.int31(), INT32_C(1407315077));
    ASSERT_EQ(rand.int31(), INT32_C(1926657288));
    ASSERT_EQ(rand.int31(), INT32_C(359390928));
    ASSERT_EQ(rand.int31(), INT32_C(619732968));
    ASSERT_EQ(rand.int31(), INT32_C(1938329147));
    ASSERT_EQ(rand.int31(), INT32_C(1824889259));
    ASSERT_EQ(rand.int31(), INT32_C(586363548));
    ASSERT_EQ(rand.int31(), INT32_C(1307989752));
    ASSERT_EQ(rand.int31(), INT32_C(544722126));
    ASSERT_EQ(rand.int31(), INT32_C(1663557311));
    ASSERT_EQ(rand.int31(), INT32_C(37539650));
    ASSERT_EQ(rand.int31(), INT32_C(1690228450));
    ASSERT_EQ(rand.int31(), INT32_C(1716684894));
}

TEST(go_rng_seed_recovery, int31n)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    ASSERT_EQ(rand.int31n(1), INT32_C(0));
    ASSERT_EQ(rand.int31n(10), INT32_C(4));
    ASSERT_EQ(rand.int31n(32), INT32_C(25));
    ASSERT_EQ(rand.int31n(1048576), INT32_C(310570));
    ASSERT_EQ(rand.int31n(1048577), INT32_C(857611));
    ASSERT_EQ(rand.int31n(1000000000), INT32_C(621654496));
    ASSERT_EQ(rand.int31n(1073741824), INT32_C(413258767));
    ASSERT_EQ(rand.int31n(2147483646), INT32_C(1407315077));
    ASSERT_EQ(rand.int31n(2147483647), INT32_C(1926657288));
    ASSERT_EQ(rand.int31n(1), INT32_C(0));
    ASSERT_EQ(rand.int31n(10), INT32_C(8));
    ASSERT_EQ(rand.int31n(32), INT32_C(27));
    ASSERT_EQ(rand.int31n(1048576), INT32_C(367019));
    ASSERT_EQ(rand.int31n(1048577), INT32_C(209005));
    ASSERT_EQ(rand.int31n(1000000000), INT32_C(307989752));
    ASSERT_EQ(rand.int31n(1073741824), INT32_C(544722126));
    ASSERT_EQ(rand.int31n(2147483646), INT32_C(1663557311));
    ASSERT_EQ(rand.int31n(2147483647), INT32_C(37539650));
    ASSERT_EQ(rand.int31n(1), INT32_C(0));
    ASSERT_EQ(rand.int31n(10), INT32_C(4));
}

TEST(go_rng_seed_recovery, int31n_template)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    ASSERT_EQ(rand.int31n<1>(), INT32_C(0));
    ASSERT_EQ(rand.int31n<10>(), INT32_C(4));
    ASSERT_EQ(rand.int31n<32>(), INT32_C(25));
    ASSERT_EQ(rand.int31n<1048576>(), INT32_C(310570));
    ASSERT_EQ(rand.int31n<1048577>(), INT32_C(857611));
    ASSERT_EQ(rand.int31n<1000000000>(), INT32_C(621654496));
    ASSERT_EQ(rand.int31n<1073741824>(), INT32_C(413258767));
    ASSERT_EQ(rand.int31n<2147483646>(), INT32_C(1407315077));
    ASSERT_EQ(rand.int31n<2147483647>(), INT32_C(1926657288));
    ASSERT_EQ(rand.int31n<1>(), INT32_C(0));
    ASSERT_EQ(rand.int31n<10>(), INT32_C(8));
    ASSERT_EQ(rand.int31n<32>(), INT32_C(27));
    ASSERT_EQ(rand.int31n<1048576>(), INT32_C(367019));
    ASSERT_EQ(rand.int31n<1048577>(), INT32_C(209005));
    ASSERT_EQ(rand.int31n<1000000000>(), INT32_C(307989752));
    ASSERT_EQ(rand.int31n<1073741824>(), INT32_C(544722126));
    ASSERT_EQ(rand.int31n<2147483646>(), INT32_C(1663557311));
    ASSERT_EQ(rand.int31n<2147483647>(), INT32_C(37539650));
    ASSERT_EQ(rand.int31n<1>(), INT32_C(0));
    ASSERT_EQ(rand.int31n<10>(), INT32_C(4));
}

TEST(go_rng_seed_recovery, int63)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    ASSERT_EQ(rand.int63(), INT64_C(8717895732742165505));
    ASSERT_EQ(rand.int63(), INT64_C(2259404117704393152));
    ASSERT_EQ(rand.int63(), INT64_C(6050128673802995827));
    ASSERT_EQ(rand.int63(), INT64_C(501233450539197794));
    ASSERT_EQ(rand.int63(), INT64_C(3390393562759376202));
    ASSERT_EQ(rand.int63(), INT64_C(2669985732393126063));
    ASSERT_EQ(rand.int63(), INT64_C(1774932891286980153));
    ASSERT_EQ(rand.int63(), INT64_C(6044372234677422456));
    ASSERT_EQ(rand.int63(), INT64_C(8274930044578894929));
    ASSERT_EQ(rand.int63(), INT64_C(1543572285742637646));
    ASSERT_EQ(rand.int63(), INT64_C(2661732831099943416));
    ASSERT_EQ(rand.int63(), INT64_C(8325060299420976708));
    ASSERT_EQ(rand.int63(), INT64_C(7837839688282259259));
    ASSERT_EQ(rand.int63(), INT64_C(2518412263346885298));
    ASSERT_EQ(rand.int63(), INT64_C(5617773211005988520));
    ASSERT_EQ(rand.int63(), INT64_C(2339563716805116249));
    ASSERT_EQ(rand.int63(), INT64_C(7144924247938981575));
    ASSERT_EQ(rand.int63(), INT64_C(161231572858529631));
    ASSERT_EQ(rand.int63(), INT64_C(7259475919510918339));
    ASSERT_EQ(rand.int63(), INT64_C(7373105480197164748));
}

TEST(go_rng_seed_recovery, int63n)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    ASSERT_EQ(rand.int63n(1), INT64_C(0));
    ASSERT_EQ(rand.int63n(10), INT64_C(2));
    ASSERT_EQ(rand.int63n(32), INT64_C(19));
    ASSERT_EQ(rand.int63n(1048576), INT64_C(959842));
    ASSERT_EQ(rand.int63n(1048577), INT64_C(688912));
    ASSERT_EQ(rand.int63n(1000000000), INT64_C(393126063));
    ASSERT_EQ(rand.int63n(1073741824), INT64_C(89212473));
    ASSERT_EQ(rand.int63n(2147483646), INT64_C(834026388));
    ASSERT_EQ(rand.int63n(2147483647), INT64_C(1577188963));
    ASSERT_EQ(rand.int63n(1000000000000000000), INT64_C(543572285742637646));
    ASSERT_EQ(rand.int63n(1152921504606846976), INT64_C(355889821886249464));
    ASSERT_EQ(rand.int63n(9223372036854775806), INT64_C(8325060299420976708));
    ASSERT_EQ(rand.int63n(9223372036854775807), INT64_C(7837839688282259259));
    ASSERT_EQ(rand.int63n(1), INT64_C(0));
    ASSERT_EQ(rand.int63n(10), INT64_C(0));
    ASSERT_EQ(rand.int63n(32), INT64_C(25));
    ASSERT_EQ(rand.int63n(1048576), INT64_C(679623));
    ASSERT_EQ(rand.int63n(1048577), INT64_C(882178));
    ASSERT_EQ(rand.int63n(1000000000), INT64_C(510918339));
    ASSERT_EQ(rand.int63n(1073741824), INT64_C(782454476));
}

TEST(go_rng_seed_recovery, int63n_template)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    ASSERT_EQ(rand.int63n<1>(), INT64_C(0));
    ASSERT_EQ(rand.int63n<10>(), INT64_C(2));
    ASSERT_EQ(rand.int63n<32>(), INT64_C(19));
    ASSERT_EQ(rand.int63n<1048576>(), INT64_C(959842));
    ASSERT_EQ(rand.int63n<1048577>(), INT64_C(688912));
    ASSERT_EQ(rand.int63n<1000000000>(), INT64_C(393126063));
    ASSERT_EQ(rand.int63n<1073741824>(), INT64_C(89212473));
    ASSERT_EQ(rand.int63n<2147483646>(), INT64_C(834026388));
    ASSERT_EQ(rand.int63n<2147483647>(), INT64_C(1577188963));
    ASSERT_EQ(rand.int63n<1000000000000000000>(), INT64_C(543572285742637646));
    ASSERT_EQ(rand.int63n<1152921504606846976>(), INT64_C(355889821886249464));
    ASSERT_EQ(rand.int63n<9223372036854775806>(), INT64_C(8325060299420976708));
    ASSERT_EQ(rand.int63n<9223372036854775807>(), INT64_C(7837839688282259259));
    ASSERT_EQ(rand.int63n<1>(), INT64_C(0));
    ASSERT_EQ(rand.int63n<10>(), INT64_C(0));
    ASSERT_EQ(rand.int63n<32>(), INT64_C(25));
    ASSERT_EQ(rand.int63n<1048576>(), INT64_C(679623));
    ASSERT_EQ(rand.int63n<1048577>(), INT64_C(882178));
    ASSERT_EQ(rand.int63n<1000000000>(), INT64_C(510918339));
    ASSERT_EQ(rand.int63n<1073741824>(), INT64_C(782454476));
}

TEST(go_rng_seed_recovery, uint32)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    ASSERT_EQ(rand.uint32(), UINT32_C(4059586549));
    ASSERT_EQ(rand.uint32(), UINT32_C(1052117029));
    ASSERT_EQ(rand.uint32(), UINT32_C(2817310706));
    ASSERT_EQ(rand.uint32(), UINT32_C(233405013));
    ASSERT_EQ(rand.uint32(), UINT32_C(1578775030));
    ASSERT_EQ(rand.uint32(), UINT32_C(1243308993));
    ASSERT_EQ(rand.uint32(), UINT32_C(826517535));
    ASSERT_EQ(rand.uint32(), UINT32_C(2814630155));
    ASSERT_EQ(rand.uint32(), UINT32_C(3853314576));
    ASSERT_EQ(rand.uint32(), UINT32_C(718781857));
    ASSERT_EQ(rand.uint32(), UINT32_C(1239465936));
    ASSERT_EQ(rand.uint32(), UINT32_C(3876658295));
    ASSERT_EQ(rand.uint32(), UINT32_C(3649778518));
    ASSERT_EQ(rand.uint32(), UINT32_C(1172727096));
    ASSERT_EQ(rand.uint32(), UINT32_C(2615979505));
    ASSERT_EQ(rand.uint32(), UINT32_C(1089444252));
    ASSERT_EQ(rand.uint32(), UINT32_C(3327114623));
    ASSERT_EQ(rand.uint32(), UINT32_C(75079301));
    ASSERT_EQ(rand.uint32(), UINT32_C(3380456901));
    ASSERT_EQ(rand.uint32(), UINT32_C(3433369789));
}

TEST(go_rng_seed_recovery, uint64)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    ASSERT_EQ(rand.uint64(), UINT64_C(8717895732742165505));
    ASSERT_EQ(rand.uint64(), UINT64_C(2259404117704393152));
    ASSERT_EQ(rand.uint64(), UINT64_C(6050128673802995827));
    ASSERT_EQ(rand.uint64(), UINT64_C(9724605487393973602));
    ASSERT_EQ(rand.uint64(), UINT64_C(12613765599614152010));
    ASSERT_EQ(rand.uint64(), UINT64_C(11893357769247901871));
    ASSERT_EQ(rand.uint64(), UINT64_C(1774932891286980153));
    ASSERT_EQ(rand.uint64(), UINT64_C(15267744271532198264));
    ASSERT_EQ(rand.uint64(), UINT64_C(17498302081433670737));
    ASSERT_EQ(rand.uint64(), UINT64_C(1543572285742637646));
    ASSERT_EQ(rand.uint64(), UINT64_C(11885104867954719224));
    ASSERT_EQ(rand.uint64(), UINT64_C(17548432336275752516));
    ASSERT_EQ(rand.uint64(), UINT64_C(7837839688282259259));
    ASSERT_EQ(rand.uint64(), UINT64_C(2518412263346885298));
    ASSERT_EQ(rand.uint64(), UINT64_C(5617773211005988520));
    ASSERT_EQ(rand.uint64(), UINT64_C(11562935753659892057));
    ASSERT_EQ(rand.uint64(), UINT64_C(16368296284793757383));
    ASSERT_EQ(rand.uint64(), UINT64_C(161231572858529631));
    ASSERT_EQ(rand.uint64(), UINT64_C(16482847956365694147));
    ASSERT_EQ(rand.uint64(), UINT64_C(16596477517051940556));
}

TEST(go_rng_seed_recovery, peek_uint64)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    for (size_t i = 0; i < 10'000; ++i)
    {
        const auto next = rand.peek_uint64();
        const auto actual = rand.uint64();
        ASSERT_EQ(next, actual) << i;
    }
}

TEST(go_rng_seed_recovery, peek_uint64_array)
{
    go_rng_seed_recovery rand(go_rng_seed_recovery::get_raw_seed(0));

    std::vector<uint64_t> values(10'000);
    for (auto& v : values)
        v = rand.uint64();

    rand.reset_state();

    for (size_t i = 0; i < 10'000 - 5; ++i)
    {
        uint64_t next[5];
        rand.peek_uint64_array(next, std::size(next));
        for (size_t j = 0; j < 5; ++j)
        {
            ASSERT_EQ(next[j], values[i + j]) << i << ' ' << j;
        }
        rand.uint64();
    }
}

TEST(go_rng_seed_recovery, next_state)
{
    go_rng_seed_recovery rand(1);
    ASSERT_EQ(rand.current_seed(), 1);

    rand.next_state();
    ASSERT_EQ(rand.current_seed(), 1291394886);

    rand.next_state();
    ASSERT_EQ(rand.current_seed(), 407355683);
}

TEST(go_rng_seed_recovery, set_state)
{
    go_rng_seed_recovery rand(1);
    ASSERT_EQ(rand.current_seed(), 1);

    rand.set_state(1291394886);
    ASSERT_EQ(rand.current_seed(), 1291394886);

    rand.next_state();
    ASSERT_EQ(rand.current_seed(), 407355683);
}

TEST(go_rng_seed_recovery, reset_state)
{
    go_rng_seed_recovery rand(1);
    
    std::vector<uint64_t> values(1000);
    for (auto& v : values)
        v = rand.uint64();

    rand.reset_state();

    for (size_t i = 0; i < values.size(); ++i)
    {
        ASSERT_EQ(values[i], rand.uint64()) << i;
    }
}

TEST(go_rng_seed_recovery, get_raw_seed)
{
    EXPECT_EQ(go_rng_seed_recovery::get_raw_seed(1), 2075782095);
    EXPECT_EQ(go_rng_seed_recovery::get_raw_seed(2), 2004080543);
    EXPECT_EQ(go_rng_seed_recovery::get_raw_seed(3), 1932378991);
}

TEST(go_rng_seed_recovery, DISABLED_recover_normal_seed)
{
    const auto raw_seed = go_rng_seed_recovery::get_raw_seed(1);
    EXPECT_EQ(go_rng_seed_recovery::recover_normal_seed(raw_seed), 1);
}
