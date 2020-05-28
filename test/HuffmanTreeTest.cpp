#include "../BitStream.hpp"
#include "../FrequencyCounter.hpp"
#include "../HuffmanTree.hpp"

#include <gtest/gtest.h>

TEST(HuffmanTreeTest, HuffmanTreeConstructorTest){
    ASSERT_TRUE(true);
    BitStream bitStream('c');
    bitStream.loadFile("Muppets.txt");
    FrequencyCounter fc = bitStream.getFc();

    HuffmanTree HuffmanTree('c',fc.getTable());
    HuffmanTree.printTree(HuffmanTree.getRoot());
}
