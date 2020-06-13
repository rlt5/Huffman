#include "FrequencyCounter.hpp"

FrequencyCounter::FrequencyCounter(){}

void FrequencyCounter::countFrequency(char* buffer, uint32_t size){
    frequencyTable.clear();
    int character;
    for ( uint32_t i = 0; i < size; i++ ){
        character = int(buffer[i]);
        if ( character < 0 ) {
            character += 256;
        }
        frequencyTable[character]++;
    }
    numberOfCharacters = frequencyTable.size();;
}

void FrequencyCounter::countFrequency(uint32_t numberOfCharacters, char* buffer){
    frequencyTable.clear();
    // std::cout << "##### FrequencyCounter::countFrequency -> Printing Freq Table in Decompression" << std::endl;
    // print();
    this->numberOfCharacters = numberOfCharacters;
    for ( uint32_t i = 0; i < numberOfCharacters; i++ ){
        frequencyTable[int(buffer[1+i*2])] = int(buffer[2+i*2]);
    }
}

void FrequencyCounter::addCharacter(int character, uint32_t freq){
    int charac = int(character);
    if ( charac < 0 ) charac +=256;
    frequencyTable[charac] = freq;
}

map<int, uint32_t> FrequencyCounter::getTable(){
    return frequencyTable;
}

int FrequencyCounter::getNumberOfCharacters(){
    return numberOfCharacters;
}

void FrequencyCounter::print(){
    std::cout << "###### FrequencyCounter print Frequency Table" << std::endl;
    for ( auto element : frequencyTable ){
        cout << (char)element.first << "=" << (uint32_t)element.first  << " " << element.second << endl;
    }
}

void FrequencyCounter::setFreq(int character, uint32_t freq){
    frequencyTable[character] = freq;
}