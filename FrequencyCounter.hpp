#ifndef FREQUENCYCOUNTER_HPP
#define FREQUENCYCOUNTER_HPP

#include <iostream>
#include <map>
using namespace std;

const int GLOBAL_VALID_CHARS = 256;

class FrequencyCounter
{
    public:
        FrequencyCounter(char buffer[], uint32_t size);
        void FrequencyCounterPrint();
        
    private:
        map<char, uint32_t> frequencyTable;
};

#endif /* FREQUENCYCOUNTER_HPP */