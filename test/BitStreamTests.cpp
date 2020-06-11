#include "../BitStream.hpp"

#include <gtest/gtest.h>

TEST(BitStreamTests, loadFile){
    ASSERT_TRUE(true);
    BitStream bitStream(BitStream::compression);
    ASSERT_TRUE( bitStream.loadFile("Muppets.txt") == 0 );
    std::string fileContents(bitStream.getBuffer(),bitStream.getBufferLength());
    ASSERT_TRUE( fileContents.compare("that's the way it is") == 0);
    
    ASSERT_TRUE( bitStream.loadFile( "emptyFile.txt" ) == 0);
    ASSERT_TRUE( bitStream.getBufferLength() == 0 );

    bitStream.loadFile("oneCharFile.txt");
    fileContents = std::string(bitStream.getBuffer(),bitStream.getBufferLength());
    ASSERT_TRUE( bitStream.getBufferLength() == 1 );
    ASSERT_TRUE( fileContents.compare("A") == 0 );

    ASSERT_TRUE( bitStream.loadFile( "FAKEFILE.txt") == 1 );

}

TEST(BitStreamTests, writeToFile){
    ASSERT_TRUE(true);
    BitStream bitStream(0);
    ASSERT_TRUE( bitStream.loadFile("Muppets.txt") == 0 );
    bitStream.writeToFile("outputTest.txt");
}

TEST(BitStreamTests, decompressionLoadFile){
    ASSERT_TRUE(true);
    BitStream bitStream(BitStream::decompression);
    ASSERT_TRUE( bitStream.loadFile("output.txt") == 0 );
    HuffmanTree* huffmanTree = bitStream.getHuffmanTree();
    // huffmanTree->printCodeTable();
}

TEST(BitStreamTests, compressAndDecompressSmallFile){
    ASSERT_TRUE(true);
    BitStream cbitStream(BitStream::compression);
    ASSERT_TRUE( cbitStream.loadFile("Muppets.txt") == 0 );
    cbitStream.writeToFile("cMuppets.txt");
    cbitStream.getFc().print();
    cbitStream.getHuffmanTree()->printCodeMap();

    BitStream dbitStream(BitStream::decompression);
    ASSERT_TRUE( dbitStream.loadFile("cMuppets.txt") == 0 );
    dbitStream.writeToFile("dMuppets.txt");
    dbitStream.getHuffmanTree()->printCodeMap();

}

TEST(BitStreamTests, compressAndDecompressLargeFile){
    ASSERT_TRUE(true);
    BitStream cbitStream(BitStream::compression);
    ASSERT_TRUE( cbitStream.loadFile("MontyPythonandtheHolyGrail.txt") == 0 );
    cbitStream.writeToFile("cMontyPythonandtheHolyGrail.txt");
    cbitStream.getFc().print();
    cbitStream.getHuffmanTree()->printCodeMap();

    BitStream dbitStream(BitStream::decompression);
    ASSERT_TRUE( dbitStream.loadFile("cMontyPythonandtheHolyGrail.txt") == 0 );
    dbitStream.writeToFile("dMontyPythonandtheHolyGrail.txt");
    dbitStream.getHuffmanTree()->printCodeMap();

}