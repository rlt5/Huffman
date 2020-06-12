#include "BitStream.hpp"
#include <cmath>
#include <assert.h> 



BitStream::BitStream(int mode){
    this->mode = mode;
    this->outputBufferLength = 0;
    this->currentIndex = 0; 
    this->huffmanTree = NULL;
    
    this->currentBit = 7;
    this->bitBuffer = 0;

    this->buffer = NULL;
    this->bufferLength;
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
        std::cout << inputFileName << " -> " << bufferLength << " bytes" << std::endl;
        if (bufferLength == 0)
            return 0;

        buffer = new char[bufferLength];
        is.read(buffer,bufferLength);
        is.close();

        if ( mode == compression ){
            outputBufferLength = bufferLength *8;
            outputBuffer = new char[outputBufferLength];
            int tempBufferLength = bufferLength;
            int byteCountLength = 0;
            while ( tempBufferLength){
                tempBufferLength /= 10;
                byteCountLength++;
            }
            outputBuffer[currentIndex] = byteCountLength; // First thing we put in is original file length bytes 
            currentIndex++;
            byteCountLength;
            tempBufferLength = bufferLength;
            while ( tempBufferLength || byteCountLength ){
                outputBuffer[currentIndex] = tempBufferLength / pow(10,byteCountLength-1);
                tempBufferLength = tempBufferLength % (int)pow(10,byteCountLength-1);
                byteCountLength--;
                currentIndex++;
            }

            fc.countFrequency(buffer, bufferLength);
            this->huffmanTree = new HuffmanTree(fc.getTable()); // HuffmanTree creates the codeTable from the FC table
            writeFCToBuffer();
            writeOriginalToOutputBuffer();
            return 0;
        } else if ( mode == decompression ){
            int originalFileLength = 0;
            int numberOfBits = buffer[currentIndex];
            currentIndex++;
            while ( numberOfBits ){
                originalFileLength = originalFileLength*10 + buffer[currentIndex];
                currentIndex++;
                numberOfBits--;
            }
            outputBufferLength = originalFileLength;
            outputBuffer = new char[outputBufferLength];
            std::cout << "LAST BINARY LETTER: " << (int)buffer[bufferLength-1] << std::endl;
            // std::cout << "##### BitStream::loadFile -> buffer[0]*2+2 = " << buffer[0]*2+2 << std::endl;
            // fc.countFrequency(uint32_t(buffer[0]), buffer);
            int numberOfCharacters = buffer[currentIndex];
            currentIndex++;
            // std::cout << "Number of Characters in Huffman Coding Table is: " << (int)numberOfCharacters << std::endl;
            readFrequencyTable(numberOfCharacters, buffer);

            this->huffmanTree = new HuffmanTree(fc.getTable()); // HuffmanTree creates the codeTable from the FC table

            writeCompressedToOutputBuffer();

            return 0;
        }
    } 
    return 1;
}


// The number of unique characters is the first byte
// The size of the original file is in the second byte
// The encoding map is after in the form of <char, uint32_t>
// After is the data 
void BitStream::writeFCToBuffer(){
    std::string* codeTable = huffmanTree->getCodeTable();
    outputBuffer[currentIndex] = fc.getNumberOfCharacters();
    currentIndex++;
    map<char, uint32_t> frequencyCountTable = fc.getTable();
    for ( int i = 0; i < 256; i++ ){
        if ( codeTable[i].compare("") != 0 ){
            outputBuffer[currentIndex] = i; // Write the character
            currentIndex++;
            int temp = frequencyCountTable[i];
            int byteCount = 0;
            while ( temp ){
                temp /= 10;
                byteCount++;
            }
            outputBuffer[currentIndex] = byteCount; // Write the number of bits to read
            currentIndex++;
            temp = frequencyCountTable[i];
            while ( temp || byteCount){
                outputBuffer[currentIndex] = temp / pow(10,byteCount-1);
                temp = temp % (int)pow(10,byteCount-1);
                byteCount--;
                currentIndex++;
            }
            
        }
    }
    // outputBufferLength = fc.getTable().size()*2 + 1;
    // assert(currentIndex == fc.getTable().size()*2 + 2) ;
}


char* BitStream::getBuffer(){
    return this->buffer;
}

int BitStream::getBufferLength(){
    return this->bufferLength;
}

void BitStream::writeCompressedToOutputBuffer(){
    // std::cout << "###### BitStream writeCompressedToOutputBuffer" << std::endl;
    HuffmanNode* currentNode;
    uint32_t bit;
    // std::cout << currentIndex << " " << buffer[currentIndex] << " ->";
    for ( uint32_t i = 0; i < outputBufferLength; i++ ){
        // std::cout << " ";
        currentNode = huffmanTree->getRoot();
        while ( !currentNode->isLeaf() ){
            if ( currentBit == -1 ){
                currentBit = 7;
                currentIndex++;
                // std::cout << std::endl;
                // std::cout << currentIndex << " " << buffer[currentIndex] << " -> ";
            }
            bit = buffer[currentIndex] >> currentBit & 1;
            if ( bit ){ // go right
                // std::cout << 1;
                currentNode = currentNode->right;
            } else { // go left
                // std::cout << 0;
                currentNode = currentNode->left;
            }
            currentBit--;
        }
        outputBuffer[i] = currentNode->character;
    }
    // outputBufferLength = currentIndex;
    std::cout << "outputBufferLength = " << currentIndex << std::endl;
    // std::cout << std::endl;
}

void BitStream::readFrequencyTable(int numberOfCharacters, char* buffer){
    char character;
    int frequency;
    uint32_t numberOfBits = 0;
    for (int i = 0; i < numberOfCharacters; i++ ){
        character = buffer[currentIndex];
        currentIndex++;
        numberOfBits = buffer[currentIndex];
        frequency = 0;
        // std::cout << "numberOfBits = " << numberOfBits << std::endl;
        currentIndex++;
        while(numberOfBits){
            frequency = frequency*10 + buffer[currentIndex];
            currentIndex++;
            numberOfBits--;
        }
        fc.addCharacter(character, frequency);
    }
}

void BitStream::writeOriginalToOutputBuffer(){
    std::string* codeTable = huffmanTree->getCodeTable();
    for ( uint32_t i = 0; i < bufferLength; i++ ){
        char currentChar = buffer[i];
        for ( char character : codeTable[currentChar]){
            writeToBit(character-48);
        }
    }
    checkLastBit();
    outputBufferLength = currentIndex;

    // std::cout << "outputbufferlength = " << outputBufferLength << std::endl;
    // checkLastBit();
}

void BitStream::printOutputBuffer(){
    std::cout << "###### BitStream printOutputBuffer" << std::endl;
    std::cout << "Output Buffer Length: " << outputBufferLength << std::endl;
    for ( uint32_t i = 0; i < outputBufferLength; i++ ){
        std::cout << outputBuffer[i];
    }
    std::cout << std::endl;
}

void BitStream::writeToBit(int bit){
    if ( bit ) setNthBit();
    currentBit--;
    if ( currentBit == -1 ){
        outputBuffer[currentIndex] = bitBuffer;
        bitBuffer = 0;
        currentBit = 7;
        currentIndex++;
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