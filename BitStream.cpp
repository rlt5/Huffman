#include "BitStream.hpp"

BitStream::BitStream(char action){
    // fstream inputFile;
    // inputFile.open(inputFileName);
    // if ( inputFile.is_open() ){
    //     inputFile << "helloWorld";
    //     inputFile.close();
    // }
    ;
}



void BitStream::loadFile(string inputFileName){

    // https://www.cplusplus.com/reference/istream/istream/seekg/
    std::ifstream is (inputFileName, std::ifstream::binary);
    if (is) {
        // get length of file:
        is.seekg (0, is.end);
        bufferLength = is.tellg();
        is.seekg (0, is.beg);
        if (bufferLength == 0)
            return;

        buffer = new char[bufferLength];
        is.read(buffer,bufferLength);
        is.close();

        fc.countFrequency(buffer, bufferLength);
    }
}

char* BitStream::getBuffer(){
    return this->buffer;
}

int BitStream::getBufferLength(){
    return this->bufferLength;
}