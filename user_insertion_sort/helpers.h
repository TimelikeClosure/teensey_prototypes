
#include <stdlib.h>

bool isEndOfList(unsigned short int charCode){
    return charCode < 32 && charCode != 11;
}

void flushStdin(){
    while(Serial.available()){
        Serial.read();
    }
}

bool isPartOfNumber(unsigned short int charCode){
    return charCode >= 48 && charCode <= 57;
}

int concatDigitToNumber(int prevNumber, unsigned int digit){
    return prevNumber * 10 + digit;
}
