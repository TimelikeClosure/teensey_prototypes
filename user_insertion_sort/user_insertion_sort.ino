
#include <stdlib.h>
#include "helpers.h"

const int led = LED_BUILTIN;

struct PseudoArray
{
  unsigned short int memberSize;
  unsigned short int count;
  int * data;
};
struct PseudoArray dataPool;

bool stdinHasData();
struct PseudoArray pullArrayFromStdin();
bool canSort(struct PseudoArray);
void sort(struct PseudoArray);

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  dataPool.memberSize = 4;
  dataPool.count = 128;
  dataPool.data = new int[dataPool.count];
}

void loop() {
  if (stdinHasData()){
    struct PseudoArray numberList = pullArrayFromStdin();
    if (canSort(numberList)){
      sort(numberList);
    }
  }
}

bool stdinHasData(){
  return Serial.available();
}

struct PseudoArray pullArrayFromStdin(){
  struct PseudoArray inputNumbers = {dataPool.memberSize, 0, dataPool.data};
  int inputNumber = 0;
  unsigned short int inputCharCode;

  while(Serial.available()){
    inputCharCode = Serial.read();
    if (isEndOfList(inputCharCode)){
      flushStdin();
      break;
    } else if (isPartOfNumber(inputCharCode)){
      inputNumber = concatDigitToNumber(inputNumber, inputCharCode);
    } else {
      if (isListFull()){
        Serial.print("Too many items provided. Only sorting first ");
        Serial.print(dataPool.count);
        Serial.println(" items.");
        flushStdin();
        emptyList(&inputNumbers);
        break;
      } else {
        concatNumberToList(&inputNumbers, inputNumber);
      }
    }
  }

  return inputNumbers;
}

bool canSort(struct PseudoArray list){
  if (list.count){
    return true;
  }
  return false;
}

void sort(struct PseudoArray list){
  int value;
  for (unsigned short int index = 0; index < list.memberSize * list.count; index++){
    value = list.data[index * list.memberSize];
    Serial.print(" ");
    Serial.print(value);
  }
  Serial.println("");
}
