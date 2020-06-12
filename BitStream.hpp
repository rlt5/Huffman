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

        enum mode{compression = 0, decompression = 1, invalid = 2};
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
        uint32_t bufferLength;
        FrequencyCounter fc;
        HuffmanTree* huffmanTree;
        
        char* outputBuffer;
        uint32_t outputBufferLength;
        void writeOriginalToOutputBuffer();
        void writeCompressedToOutputBuffer();

        uint32_t currentIndex;
        int currentBit;
        char bitBuffer;
        void writeToBit(int bit);
        void readFrequencyTable(int numberOfCharacters, char* buffer);
        void setNthBit();
        int checkLastBit();
        void writeFCToBuffer();

        void printOutputBuffer();

};

#endif /* BITSTREAM_HPP */