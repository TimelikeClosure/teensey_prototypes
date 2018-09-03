//  Blinks rapidly if the user hasn't input anything in 30 mins.

const int led = LED_BUILTIN;
unsigned short incoming;
char outgoing;
const unsigned int SNOOZE_DURATION = 1000 * 60 * 30;
elapsedMillis sinceLastPrint = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available()){
    while (Serial.available()){
      incoming = Serial.read();
      outgoing = (char) incoming;
      Serial.print(outgoing);
      sinceLastPrint = 0;
    }
    Serial.println("");
    Serial.println("---- 30 minute snooze activated ----");
  }
  if (sinceLastPrint >= SNOOZE_DURATION){
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
}
