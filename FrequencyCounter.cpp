#include "FrequencyCounter.hpp"

// FrequencyCounter::FrequencyCounter(char* buffer, uint32_t size){

//     for ( uint32_t i = 0; i < size; i++ ){
//         frequencyTable[buffer[i]]++;
//     }

// }

FrequencyCounter::FrequencyCounter(){
    ;
}

void FrequencyCounter::countFrequency(char* buffer, uint32_t size){
    frequencyTable.clear();
    for ( uint32_t i = 0; i < size; i++ ){
        frequencyTable[buffer[i]]++;
    }
}

// FrequencyCounter::FrequencyCounter(string inputFilename){
//     ifstream inputFile;
//     string line;
//     inputFile.open(inputFilename);
//     if ( inputFile.is_open() ){
//         cout << "file open" << endl;
//         while ( getline( inputFile, line) ){
//             for ( int c : line ){
//                 frequencyTable[c]++;
//             }
//         }
//         inputFile.close();
//     }
//     cout << "testing2" << endl;
// }

map<char, uint32_t> FrequencyCounter::getTable(){
    return frequencyTable;
}

void FrequencyCounter::FrequencyCounterPrint(){
    for ( auto element : frequencyTable ){
        cout << (char)element.first << "=" << element.first  << " " << element.second << endl;
    }
        
}