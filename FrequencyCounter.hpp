#ifndef FREQUENCYCOUNTER_HPP
#define FREQUENCYCOUNTER_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

const int GLOBAL_VALID_CHARS = 256;

class FrequencyCounter
{
    public:
        // FrequencyCounter(char* buffer, uint32_t size);
        // FrequencyCounter(string inputFilename);
        FrequencyCounter();
        void print();
        void countFrequency(char* buffer, uint32_t size);
        void countFrequency(uint32_t numberOfCharacters, char* buffer);
        map<char, uint32_t> getTable();
        int getNumberOfCharacters();
        
    private:
        map<char, uint32_t> frequencyTable;
        int numberOfCharacters;
};

#endif /* FREQUENCYCOUNTER_HPP */