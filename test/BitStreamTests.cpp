#include "../BitStream.hpp"

#include <gtest/gtest.h>

// using namespace std;

TEST(BitStreamTests, loadFile){
    ASSERT_TRUE(true);
    BitStream bitStream('c');
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