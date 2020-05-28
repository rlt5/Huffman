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
        BitStream(char action);
        // BitStream(char action, string inputFileName, string outputFileName, char buffer[]);
        // void readBit();
        void loadFile(string inputFileName); // This should call Frequency Counter
        char* getBuffer();
        int getBufferLength();
        FrequencyCounter getFc();
        // void setBuffer(Object buffer);

    private:
        char* buffer;
        int bufferLength;
        int currentByte;
        int bitPos;
        FrequencyCounter fc;
        // HuffmanTree huffmanTree;
};

#endif /* BITSTREAM_HPP */