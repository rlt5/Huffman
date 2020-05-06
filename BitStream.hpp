#ifndef BITSTREAM_HPP
#define BITSTREAM_HPP

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BitStream
{
    public:
        BitStream(char action, string inputFileName, string outputFileName);

    private:
        char inputBuffer[256];
        char outputBuffer[256];
        string inputFilename;
        string outputFilename;
};

#endif /* BITSTREAM_HPP */