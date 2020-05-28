#include "FrequencyCounter.hpp"

FrequencyCounter::FrequencyCounter(){}

void FrequencyCounter::countFrequency(char* buffer, uint32_t size){
    frequencyTable.clear();
    numberOfCharacters = 0;
    for ( uint32_t i = 0; i < size; i++ ){
        frequencyTable[buffer[i]]++;
        numberOfCharacters++;
    }
}

map<char, uint32_t> FrequencyCounter::getTable(){
    return frequencyTable;
}

int FrequencyCounter::getNumberOfCharacters(){
    return numberOfCharacters;
}

void FrequencyCounter::FrequencyCounterPrint(){
    for ( auto element : frequencyTable ){
        cout << (char)element.first << "=" << (int)element.first  << " " << element.second << endl;
    }
}