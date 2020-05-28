#include "../BitStream.hpp"

#include <gtest/gtest.h>

// using namespace std;

TEST(BitStreamTests, loadFile){
    ASSERT_TRUE(true);
    BitStream bitStream('c');
    bitStream.loadFile("Muppets.txt");
    std::string fileContents(bitStream.getBuffer(),bitStream.getBufferLength());
    ASSERT_TRUE( fileContents.compare("that's the way it is") == 0);
    
    bitStream.loadFile( "emptyFile.txt" );
    ASSERT_TRUE( bitStream.getBufferLength() == 0 );

    bitStream.loadFile("oneCharFile.txt");
    fileContents = std::string(bitStream.getBuffer(),bitStream.getBufferLength());
    ASSERT_TRUE( bitStream.getBufferLength() == 1 );
    ASSERT_TRUE( fileContents.compare("A") == 0 );

}