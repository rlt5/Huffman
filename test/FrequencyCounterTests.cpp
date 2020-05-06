#include "../FrequencyCounter.hpp"

#include <gtest/gtest.h>

TEST(FrequencyCounterTest, Constructor){
    ASSERT_TRUE(true);
    uint32_t size = 10;
    char buffer[] = {'a','b','a','b','a','b','a','b','a','b'};
    FrequencyCounter(buffer, size).FrequencyCounterPrint();
}

// TEST(FrequencyCounterTest, FrequencyCounterPrint){
//     ASSERT_TRUE(true);
//     uint32_t size = 10;
//     char buffer[] = {'a','b','a','b','a','b','a','b','a','b'};
//     FrequencyCounter(buffer, size);
// }