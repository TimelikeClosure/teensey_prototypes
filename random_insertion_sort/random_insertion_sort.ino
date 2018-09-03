
#include <stdlib.h>

const int led = LED_BUILTIN;

bool isNewline(unsigned short charCode);
bool isDigit(unsigned short charCode);
unsigned short toDigit(unsigned short charCode);
unsigned int appendDigitToNumber(unsigned short digit, unsigned int number);
void appendNumberToList(unsigned int number);
void printList();

unsigned short input, inputDigit;
unsigned int inputNumber;
unsigned int numberListCount = 0;
unsigned int numberListLength = 16;
unsigned int numberList[numberListLength];

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    input = Serial.read();
    if (isDigit(input)){
      inputDigit = toDigit(input);
      inputNumber = appendDigitToNumber(inputDigit, inputNumber);
      
      Serial.print(inputNumber);
    } else if (isNewline(input)){
      numberListCount = 0;
      Serial.println("");
    } else {
      appendNumberToList(inputNumber);

      printList();
      inputNumber = 0;
    }
  }
}

bool isNewline(unsigned short charCode){
  return charCode == 10;
}

bool isDigit(unsigned short charCode){
  return charCode >= 48 && charCode <= 57;
}

unsigned short toDigit(unsigned short charCode){
  return charCode - 48;
}

unsigned int appendDigitToNumber(unsigned short digit, unsigned int number){
  return 10 * number + digit;
}

void appendNumberToList(unsigned int number){
  if (numberListCount >= numberListLength){
    numberListCount = 0;
  }
  numberList[numberListCount++] = number;
}

void printList(){
  for (unsigned short i = 0; i < numberListCount; i++){
    Serial.print(numberList[i]);
    Serial.print(' ');
  }
  Serial.println("");
}
