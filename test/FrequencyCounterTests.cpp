#include "../FrequencyCounter.hpp"

#include <gtest/gtest.h>

// TEST(FrequencyCounterTest, Constructor){
//     ASSERT_TRUE(true);
//     uint32_t size = 10;
//     char buffer[] = {'a','b','a','b','a','b','a','b','a','b'};
//     FrequencyCounter(buffer, size).FrequencyCounterPrint();
// }

// TEST(FrequencyCounterTest, ReadFile){
//     ASSERT_TRUE(true);
//     uint32_t size = 10;
//     string inputFilename = "../../Muppets.txt";
//     FrequencyCounter(inputFilename).FrequencyCounterPrint();
//     EXPECT_TRUE(false);
// }

// TEST(FrequencyCounterTest, FrequencyCounterPrint){
//     ASSERT_TRUE(true);
//     uint32_t size = 10;
//     char buffer[] = {'a','b','a','b','a','b','a','b','a','b'};
//     FrequencyCounter(buffer, size);
// }

TEST(FrequencyCounterTest, countFrequency){
    ASSERT_TRUE(true);
    uint32_t size = 10;
    char buffer[] = {'a','b','a','b','a','b','a','b','a','b'}; // 5a 5b
    FrequencyCounter fc;
    map<char, uint32_t> ft = fc.getTable();
    ASSERT_TRUE(ft.empty());

    fc.countFrequency(buffer, size);
    ft = fc.getTable();
    EXPECT_TRUE(!ft.empty());
    EXPECT_FALSE(ft['a'] == 4);
    EXPECT_TRUE(ft['a'] == 5);
    EXPECT_TRUE(ft['b'] == 5);
    // fc.FrequencyCounterPrint();
}

