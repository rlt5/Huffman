#ifndef BITSTREAM_HPP
#define BITSTREAM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "HuffmanTree.hpp"
#include "FrequencyCounter.hpp"



class BitStream
{
    enum mode{compression = 0, decompression = 1, invalid = 2};

    public:

        BitStream(int mode);
        // BitStream(char action, string inputFileName, string outputFileName, char buffer[]);
        // void readBit();
        int loadFile(string inputFileName); // This should call Frequency Counter
        void writeToFile(string outputFileName);
        char* getBuffer();
        int getBufferLength();
        FrequencyCounter getFc();
        HuffmanTree* getHuffmanTree();
        // void setBuffer(Object buffer);

    private:
        int mode;
        char* buffer;
        int bufferLength;
        int currentByte;
        int bitPos;
        FrequencyCounter fc;
        HuffmanTree* huffmanTree;
        
        char* outputBuffer;
        int outputBufferLength;
        void writeToOutputBuffer();

        int currentIndex;
        int currentBit;
        char bitBuffer;
        void writeToBit(int bit);
        void setNthBit();
        int checkLastBit();
        void writeFCToBuffer();

};

#endif /* BITSTREAM_HPP */