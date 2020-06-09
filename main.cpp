#include <iostream>
#include "BitStream.hpp"
#include <gtest/gtest.h>
#include "util.hpp"

int main(int argc, char* argv[]){
    
    // Check valid number of arguments
    if ( argc != 4 ){
        std::cout << "Incorrect input format. (Ex: ./huffman -c source.txt destination.huffman) " << std::endl;
        return 0;
    }
    
    // Check valid mode input
    int mode = -1;
    if ( argv[1] == "-c" ) mode == 0;
    else if ( argv[1] == "-d" ) mode == 1;
    else {
        std::cout << "The mode input is incorrect. Please enter either -c for compression or -d for decompression." << std::endl;
        return 0;
    }

    // Load File
    BitStream bitStream(mode);
    if ( bitStream.loadFile(argv[2]) == 1 ){
        std::cout << "The file can not be found." << std::endl;
        return 0;
    }
    bitStream.writeToFile(argv[3]);
    return 0;
}