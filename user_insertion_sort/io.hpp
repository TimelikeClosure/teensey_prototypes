#include "storage.hpp"

namespace IO
{
    const int led = LED_BUILTIN;

    void setup(){

    }

    bool inputAvailable(){
        return Serial.available();
    }

    bool isEndOfList(unsigned short int charCode){
        return charCode < 32 && charCode != 11;
    }

    void flushInput(){
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

    void outputOverflowWarning(){
        Serial.print("Warning: Too many inputs. Only sorting first ");
        Serial.print(Storage::MAX_COUNT);
        Serial.println(" items.");
    }

    void storeInputData(){
        unsigned short int inputCharCode;
        int inputNumber = 0;
        Storage::empty();

        while(Serial.available()){
            inputCharCode = Serial.read();
            if (isEndOfList(inputCharCode)){
                flushInput();
                break;
            } else if (isPartOfNumber(inputCharCode)){
                inputNumber = concatDigitToNumber(inputNumber, inputCharCode);
            } else {
                if (Storage::isFull()){
                    outputOverflowWarning();
                    flushInput();
                    break;
                } else {
                    Storage::append(inputNumber);
                    inputNumber = 0;
                }
            }
        }
    }

    void ledOn(){
        digitalWrite(led, HIGH);
    }

    void ledOff(){
        digitalWrite(led, LOW);
    }

    void outputNumberFormatted(int number, char prefix, char postfix){

    }

    void outputDataPlain(){

    }

    void outputDataFormatPair(unsigned short int index1, unsigned short int index2, char prefix, char postfix){

    }
}
