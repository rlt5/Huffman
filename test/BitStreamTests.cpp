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

    // bitStream.loadFile("oneCharFile.txt");
    // fileContents = std::string(bitStream.getBuffer(),bitStream.getBufferLength());
    // ASSERT_TRUE( bitStream.getBufferLength() == 1 );
    // ASSERT_TRUE( fileContents.compare("A") == 0 );

    // ASSERT_TRUE( bitStream.loadFile( "FAKEFILE.txt") == 1 );

}

TEST(BitStreamTests, writeToFile){
    ASSERT_TRUE(true);
    BitStream bitStream(0);
    ASSERT_TRUE( bitStream.loadFile("Muppets.txt") == 0 );
    bitStream.writeToFile("outputTest.txt");
    bitStream.getHuffmanTree()->printCodeMap();
}

TEST(BitStreamTests, decompressionLoadFile){
    ASSERT_TRUE(true);
    BitStream bitStream(BitStream::decompression);
    ASSERT_TRUE( bitStream.loadFile("outputTest.txt") == 0 );
    HuffmanTree* huffmanTree = bitStream.getHuffmanTree();
    huffmanTree->printCodeMap();
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

    ASSERT_TRUE(cbitStream.getBufferLength() == dbitStream.getOutputBufferLength());
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
    dbitStream.getFc().print();
    dbitStream.getHuffmanTree()->printCodeMap();

    ASSERT_TRUE(cbitStream.getBufferLength() == dbitStream.getOutputBufferLength());
}

TEST(BitStreamTests, aoutFile){
    ASSERT_TRUE(true);
    BitStream cbitStream(BitStream::compression);
    ASSERT_TRUE( cbitStream.loadFile("a.out") == 0 );
    cbitStream.writeToFile("ca.out");
    cbitStream.getFc().print();
    cbitStream.getHuffmanTree()->printCodeMap();
    

    BitStream dbitStream(BitStream::decompression);
    ASSERT_TRUE( dbitStream.loadFile("ca.out") == 0 );
    dbitStream.writeToFile("da.out");
    dbitStream.getFc().print();
    dbitStream.getHuffmanTree()->printCodeMap();
    
    ASSERT_TRUE(cbitStream.getBufferLength() == dbitStream.getOutputBufferLength());
}

TEST(BitStreamTests, euroTxt){
    ASSERT_TRUE(true);
    BitStream cbitStream(BitStream::compression);
    ASSERT_TRUE( cbitStream.loadFile("euro.txt") == 0 );
    cbitStream.writeToFile("ceuro.txt");
    cbitStream.getFc().print();
    cbitStream.getHuffmanTree()->printCodeMap();
    

    BitStream dbitStream(BitStream::decompression);
    ASSERT_TRUE( dbitStream.loadFile("ceuro.txt") == 0 );
    dbitStream.writeToFile("deuro.txt");
    dbitStream.getFc().print();
    dbitStream.getHuffmanTree()->printCodeMap();
    
    ASSERT_TRUE(cbitStream.getBufferLength() == dbitStream.getOutputBufferLength());
}