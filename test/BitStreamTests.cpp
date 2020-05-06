#include "../BitStream.hpp"

#include <gtest/gtest.h>

TEST(BitStreamTests, Square){
    ASSERT_TRUE(true);
    BitStream('d', "TestInputFile.txt", "TestOutputFile.txt");
    
}