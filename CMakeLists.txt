cmake_minimum_required(VERSION 3.17)

project(go-rng-seed-recovery LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(benchmark REQUIRED)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_library(${PROJECT_NAME}-library STATIC go_rng_seed_recovery.cpp go_rng_seed_recovery.hpp)

add_executable(${PROJECT_NAME}-benchmark go_rng_seed_recovery_benchmark.cpp)
target_link_libraries(${PROJECT_NAME}-benchmark PRIVATE benchmark::benchmark ${PROJECT_NAME}-library)

add_executable(${PROJECT_NAME}-example go_rng_seed_recovery_example.cpp)
target_link_libraries(${PROJECT_NAME}-example Threads::Threads ${PROJECT_NAME}-library)

add_executable(${PROJECT_NAME}-test go_rng_seed_recovery_test.cpp)
target_link_libraries(${PROJECT_NAME}-test PRIVATE GTest::gtest GTest::gtest_main ${PROJECT_NAME}-library)

enable_testing()
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-test)
