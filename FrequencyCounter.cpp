#include "FrequencyCounter.hpp"

FrequencyCounter::FrequencyCounter(){}

void FrequencyCounter::countFrequency(char* buffer, uint32_t size){
    frequencyTable.clear();
    for ( uint32_t i = 0; i < size; i++ ){
        frequencyTable[buffer[i]]++;
    }
    numberOfCharacters = frequencyTable.size();;
}

void FrequencyCounter::countFrequency(uint32_t numberOfCharacters, char* buffer){
    frequencyTable.clear();
    this->numberOfCharacters = numberOfCharacters;
    for ( uint32_t i = 0; i < numberOfCharacters; i++ ){
        frequencyTable[buffer[1+i*2]] = buffer[2+i*2];
    }
}

map<char, uint32_t> FrequencyCounter::getTable(){
    return frequencyTable;
}

int FrequencyCounter::getNumberOfCharacters(){
    return numberOfCharacters;
}

void FrequencyCounter::print(){
    for ( auto element : frequencyTable ){
        cout << (char)element.first << "=" << (int)element.first  << " " << element.second << endl;
    }
}