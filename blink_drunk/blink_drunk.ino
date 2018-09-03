

#include <stdlib.h>

const int led = LED_BUILTIN;
float randomNum;
unsigned int randomBlink;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("==== START ====");
  digitalWrite(led, HIGH);
  
  randomNum = rand();
  randomNum /= RAND_MAX;
  randomNum *= 1000.;
  randomBlink = (unsigned int)randomNum;
  Serial.print("RandomBlink on: ");
  Serial.print(randomBlink);
  
  digitalWrite(led, HIGH);
  delay(randomBlink);
  
  randomNum = rand();
  randomNum /= RAND_MAX;
  randomNum *= 1000.;
  randomBlink = (unsigned int)randomNum;
  
  Serial.print(" RandomBlink off: ");
  Serial.println(randomBlink);
  
  digitalWrite(led, LOW);
  delay(randomBlink);
}
