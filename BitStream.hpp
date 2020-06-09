#ifndef BITSTREAM_HPP
#define BITSTREAM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "HuffmanTree.hpp"
#include "FrequencyCounter.hpp"



class BitStream
{
    public:
        BitStream(int mode);
        // BitStream(char action, string inputFileName, string outputFileName, char buffer[]);
        // void readBit();
        int loadFile(string inputFileName); // This should call Frequency Counter
        int writeToFile(string outputFileName);
        char* getBuffer();
        int getBufferLength();
        FrequencyCounter getFc();
        // void setBuffer(Object buffer);

    private:
        int mode;
        char* buffer;
        int bufferLength;
        int currentByte;
        int bitPos;
        FrequencyCounter fc;
        HuffmanTree huffmanTree;
        
        char* outputBuffer;
        int outputBufferLength;
        void writeToOutputBuffer();
};

#endif /* BITSTREAM_HPP */