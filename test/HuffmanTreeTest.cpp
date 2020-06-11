#include "../BitStream.hpp"
#include "../FrequencyCounter.hpp"
#include "../HuffmanTree.hpp"

#include <gtest/gtest.h>

TEST(HuffmanTreeTest, HuffmanTreeConstructorTest){
    ASSERT_TRUE(true);
    BitStream bitStream(0);
    bitStream.loadFile("Muppets.txt");
    FrequencyCounter fc = bitStream.getFc();

    HuffmanTree HuffmanTree(fc.getTable());
    
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
    ASSERT_TRUE(codeTable['a'] == "000");
    ASSERT_TRUE(codeTable['h'] == "001");
    ASSERT_TRUE(codeTable['i'] == "010");
    ASSERT_TRUE(codeTable['s'] == "011");
    ASSERT_TRUE(codeTable['\''] == "1000");
    ASSERT_TRUE(codeTable['e'] == "1001");
    ASSERT_TRUE(codeTable['w'] == "1010");
    ASSERT_TRUE(codeTable['y'] == "1011");
    ASSERT_TRUE(codeTable[' '] == "110");
    ASSERT_TRUE(codeTable['t'] == "111");
}

// TEST(HuffmanTreeTest, HuffmanTreePrintTests){
//     ASSERT_TRUE(true);
//     BitStream bitStream(0);
//     bitStream.loadFile("Muppets.txt");
//     FrequencyCounter fc = bitStream.getFc();

//     HuffmanTree HuffmanTree(fc.getTable());
//     HuffmanTree.printTreeByLevel();
//     HuffmanTree.printInOrderTraversal();
//     HuffmanTree.printLeavesInOrder();
//     HuffmanTree.printCodeTable();
// }


