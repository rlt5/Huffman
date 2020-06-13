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
        map<int, uint32_t> getTable();
        int getNumberOfCharacters();
        void addCharacter(int character, uint32_t freq);
        void setFreq(int character, uint32_t freq);
        
    private:
        map<int, uint32_t> frequencyTable;
        int numberOfCharacters;
};

#endif /* FREQUENCYCOUNTER_HPP */