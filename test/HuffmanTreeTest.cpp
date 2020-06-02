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
    
    // Initialize codeTable to 0;
    int* codeTable = HuffmanTree.getCodeTable();
    for ( int i = 0; i < 256; i++ ){
        ASSERT_TRUE(codeTable[i] == 0);
    }
}

TEST(HuffmanTreeTest, HuffmanTreePrintTests){
    ASSERT_TRUE(true);
    BitStream bitStream('c');
    bitStream.loadFile("Muppets.txt");
    FrequencyCounter fc = bitStream.getFc();

    HuffmanTree HuffmanTree('c',fc.getTable());
    HuffmanTree.printTreeByLevel();
    HuffmanTree.printInOrderTraversal();
    HuffmanTree.printLeavesInOrder();
}


