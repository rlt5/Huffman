#include "BitStream.hpp"
#include <assert.h> 



BitStream::BitStream(int mode){
    this->mode = mode;
    this->outputBufferLength = 0;
    if ( mode == compression ) this->currentIndex = 0; 
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
            outputBufferLength = bufferLength + 256 * 2 + 1;
            outputBuffer = new char[outputBufferLength];

            fc.countFrequency(buffer, bufferLength);
            this->huffmanTree = new HuffmanTree(fc.getTable()); // HuffmanTree creates the codeTable from the FC table
            writeFCToBuffer();
            writeOriginalToOutputBuffer();
            return 0;
        } else if ( mode == decompression ){
            outputBufferLength = bufferLength * 8 + 1;
            outputBuffer = new char[outputBufferLength];
            currentIndex = buffer[0]*2+1;
            std::cout << "##### BitStream::loadFile -> buffer[0]*2+2 = " << buffer[0]*2+2 << std::endl;
            // std::cout << "Number of Characters in Huffman Coding Table is: " << int(buffer[0]) << std::endl;
            fc.countFrequency(uint32_t(buffer[0]), buffer);
            this->huffmanTree = new HuffmanTree(fc.getTable()); // HuffmanTree creates the codeTable from the FC table
            // fc.print();
            // huffmanTree->printCodeMap();
            writeCompressedToOutputBuffer();
            // printOutputBuffer();
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
    outputBuffer[currentIndex] = fc.getNumberOfCharacters();
    currentIndex++;
    map<uint32_t, uint32_t> frequencyCountTable = fc.getTable();
    for ( std::pair<char, uint32_t> element : frequencyCountTable ){
        outputBuffer[currentIndex] = element.first;
        currentIndex++;
        outputBuffer[currentIndex] = char(element.second);
        currentIndex++;
    }
    outputBufferLength = fc.getTable().size()*2 + 1;
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
    // std::cout << std::endl;
}

void BitStream::writeOriginalToOutputBuffer(){
    HuffmanTree* huffmanTree = getHuffmanTree();
    std::string* codeTable = huffmanTree->getCodeTable();
    for ( uint32_t i = 0; i < bufferLength; i++ ){
        char currentChar = buffer[i];
        for ( char character : codeTable[currentChar]){
            writeToBit(character-48);
        }
    }
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