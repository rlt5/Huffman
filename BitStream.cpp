#include "BitStream.hpp"
#include <iostream>
#include <fstream>
#include <string>

BitStream::BitStream(char action, string inputFileName, string outputFileName){
    fstream inputFile;
    inputFile.open(inputFileName);
    if ( inputFile.is_open() ){
        inputFile << "helloWorld";
        inputFile.close();
    }
}

// BitStream::read(string inputFileName){

// }
