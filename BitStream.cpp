#include "BitStream.hpp"

BitStream::BitStream(int mode){
    this->mode = mode;
    this->outputBufferLength = 0;
    this->currentIndex = 0;
    this->currentBit = 7;
    this->huffmanTree = NULL;
    this->bitBuffer = NULL;
    this->buffer = NULL;
    this->bufferLength;
    this->currentByte;
    this->bitPos;
}

FrequencyCounter BitStream::getFc(){
    return fc;
}

HuffmanTree* BitStream::getHuffmanTree(){
    return this->huffmanTree;
}


int BitStream::loadFile(string inputFileName){

    // https://www.cplusplus.com/reference/istream/istream/seekg/
    std::ifstream is(inputFileName, std::ifstream::binary);
    if (is) {
        // get length of file:
        is.seekg (0, is.end);
        bufferLength = is.tellg();
        is.seekg (0, is.beg);
        if (bufferLength == 0)
            return 0;

        buffer = new char[bufferLength];
        is.read(buffer,bufferLength);
        is.close();

        fc.countFrequency(buffer, bufferLength);
        this->huffmanTree = new HuffmanTree('c',fc.getTable()); // HuffmanTree creates the codeTable from the FC table
        writeToOutputBuffer();
        return 0;
    } 
    return 1;
}

char* BitStream::getBuffer(){
    return this->buffer;
}

int BitStream::getBufferLength(){
    return this->bufferLength;
}

void BitStream::writeToOutputBuffer(){
    HuffmanTree* huffmanTree = getHuffmanTree();
    std::string* codeTable = huffmanTree->getCodeTable();
    for ( int i = 0; i < bufferLength; i++ ){
        char currentChar = buffer[i];
        for ( char character : codeTable[currentChar]){
            std::cout << character;
            writeToBit(character-48);
        }
        std::cout << ",";
    }
    outputBufferLength = currentIndex;
    std::cout << std::endl;
    std::cout << "outputbufferlength = " << outputBufferLength << std::endl;
    // checkLastBit();
}


void BitStream::writeToBit(int bit){
    // std::cout << "writeToBit" << std::endl;
    std::cout << currentBit << ",";
    if ( bit ) setNthBit();
    currentBit--;
    if ( currentBit == -1 ){
        outputBuffer[currentIndex] = bitBuffer;
        currentIndex++;
        bitBuffer = 0;
        currentBit = 7;
    }
}

int BitStream::checkLastBit(){
    int result = 0;
    if ( currentBit != 7 ){
        result = 1 + currentBit;
        currentBit = 7;
        outputBuffer[currentIndex] = bitBuffer;
        currentIndex++;
        bitBuffer = 0;
    }
    return result;
}

void BitStream::setNthBit(){
    bitBuffer |= ( 1 << currentBit );
}

void BitStream::writeToFile(string outputFileName){
    std::ofstream of(outputFileName, std::ofstream::binary);
    of.write( outputBuffer, outputBufferLength );
    of.close();
    if (mode == 0){
        std::cout << outputFileName << " -> " << outputBufferLength << " bytes" << std::endl;
        if ( outputBufferLength > bufferLength ){
            std::cout << "*** Size of compressed file > size of source file ***" << std::endl;
        }
    }
}