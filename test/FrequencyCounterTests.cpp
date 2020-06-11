#include "../FrequencyCounter.hpp"
#include "../BitStream.hpp"

#include <gtest/gtest.h>

TEST(FrequencyCounterTest, print){
    ASSERT_TRUE(true);
    uint32_t size = 10;
    char buffer[] = {'a','b','a','b','a','b','a','b','a','b'};
    FrequencyCounter fc;
    fc.countFrequency(buffer, size);
    fc.print();
}

TEST(FrequencyCounterTest, countFrequency){
    ASSERT_TRUE(true);
    uint32_t size = 10;
    char buffer[] = {'a','b','a','b','a','b','a','b','a','b'}; // 5a 5b
    FrequencyCounter fc;
    map<uint32_t, uint32_t> ft = fc.getTable();
    ASSERT_TRUE(ft.empty());

    fc.countFrequency(buffer, size);
    ft = fc.getTable();
    EXPECT_TRUE(!ft.empty());
    EXPECT_FALSE(ft['a'] == 4);
    EXPECT_TRUE(ft['a'] == 5);
    EXPECT_TRUE(ft['b'] == 5);
    
    BitStream bitStream('c');
    bitStream.loadFile("Muppets.txt");
    std::string fileContents(bitStream.getBuffer(),bitStream.getBufferLength());
    fc.countFrequency(bitStream.getBuffer(),bitStream.getBufferLength());
    ft = fc.getTable();
    EXPECT_TRUE(ft['t'] == 4 );
    EXPECT_TRUE(ft[' '] == 4 );
    EXPECT_TRUE(ft['a'] == 2 );
    EXPECT_TRUE(ft['h'] == 2 );
    EXPECT_TRUE(ft['i'] == 2 );
    EXPECT_TRUE(ft['s'] == 2 );
    EXPECT_TRUE(ft['\''] == 1 );
    EXPECT_TRUE(ft['e'] == 1 );
    EXPECT_TRUE(ft['w'] == 1 );
    EXPECT_TRUE(ft['y'] == 1 );
    fc.print();

}

