namespace IO
{
    void setup(){

    }

    bool inputAvailable(){

        return false;
    }

    void storeInputData(){

    }

    // bool isEndOfList(unsigned short int charCode){
    //     return charCode < 32 && charCode != 11;
    // }

    // void flushStdin(){
    //     while(Serial.available()){
    //         Serial.read();
    //     }
    // }

    // bool isPartOfNumber(unsigned short int charCode){
    //     return charCode >= 48 && charCode <= 57;
    // }

    // int concatDigitToNumber(int prevNumber, unsigned int digit){
    //     return prevNumber * 10 + digit;
    // }

    // bool stdinHasData(){
    // return Serial.available();
    // }

    // struct PseudoArray pullArrayFromStdin(){
    // struct PseudoArray inputNumbers = {dataPool.memberSize, 0, dataPool.data};
    // int inputNumber = 0;
    // unsigned short int inputCharCode;

    // while(Serial.available()){
    //     inputCharCode = Serial.read();
    //     if (isEndOfList(inputCharCode)){
    //     flushStdin();
    //     break;
    //     } else if (isPartOfNumber(inputCharCode)){
    //     inputNumber = concatDigitToNumber(inputNumber, inputCharCode);
    //     } else {
    //     if (isListFull()){
    //         Serial.print("Too many items provided. Only sorting first ");
    //         Serial.print(dataPool.count);
    //         Serial.println(" items.");
    //         flushStdin();
    //         emptyList(&inputNumbers);
    //         break;
    //     } else {
    //         concatNumberToList(&inputNumbers, inputNumber);
    //     }
    //     }
    // }

    // return inputNumbers;
    // }
}
