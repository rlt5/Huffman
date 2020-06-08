#include "BitStream.hpp"

BitStream::BitStream(int mode){
    this->mode = mode;
    // fstream inputFile;
    // inputFile.open(inputFileName);
    // if ( inputFile.is_open() ){
    //     inputFile << "helloWorld";
    //     inputFile.close();
    // }
    ;
}

FrequencyCounter BitStream::getFc(){
    return fc;
}



int BitStream::loadFile(string inputFileName){

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
        return 0;
    } 
    else 
        return 1;
}

char* BitStream::getBuffer(){
    return this->buffer;
}

int BitStream::getBufferLength(){
    return this->bufferLength;
}