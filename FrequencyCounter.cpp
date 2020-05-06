#include "FrequencyCounter.hpp"

FrequencyCounter::FrequencyCounter(char* buffer, uint32_t size){
    for ( int i = 0; i < GLOBAL_VALID_CHARS; i++ ){
        frequencyTable[i] = 0;
    }
    for ( uint32_t i = 0; i < size; i++ ){
        frequencyTable[buffer[i]]++;
    }

}
void FrequencyCounter::FrequencyCounterPrint(){
    for ( int i = 0; i < GLOBAL_VALID_CHARS; i++ ){
        cout << (char)i << "=" << i  << " " << frequencyTable[i];
        if ( frequencyTable[i] > 0 ) 
            cout << " <---" << endl;
        else 
            cout << endl;
        
    }
}