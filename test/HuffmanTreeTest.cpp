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
    std::string* codeTable = HuffmanTree.getCodeTable();
    for ( int i = 0; i < 256; i++ ){
        if (    i != 'a' &&
                i != 'h' &&
                i != 'i' &&
                i != 's' &&
                i != '\'' &&
                i != 'e' &&
                i != 'w' &&
                i != 'y' &&
                i != ' ' &&
                i != 't' ){
            ASSERT_TRUE(codeTable[i].empty()) << i ;
            }
    }
    ASSERT_TRUE(codeTable['a'].compare("000") == 0);
    ASSERT_TRUE(codeTable['h'].compare("001") == 0);
    ASSERT_TRUE(codeTable['i'].compare("010") == 0);
    ASSERT_TRUE(codeTable['s'].compare("011") == 0);
    ASSERT_TRUE(codeTable['\''].compare("1000") == 0);
    ASSERT_TRUE(codeTable['e'].compare("1001") == 0);
    ASSERT_TRUE(codeTable['w'].compare("1010") == 0);
    ASSERT_TRUE(codeTable['y'].compare("1011") == 0);
    ASSERT_TRUE(codeTable[' '].compare("110") == 0);
    ASSERT_TRUE(codeTable['t'].compare("111") == 0);
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
    HuffmanTree.printCodeTable();
}


