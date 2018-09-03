// Takes user input and sends it right back to the user

const int led = LED_BUILTIN;
unsigned short incoming;
char outgoing;
unsigned short lastAvailable = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available()){
    if (!lastAvailable){
      lastAvailable = 1;
      digitalWrite(led, HIGH);
    }
    incoming = Serial.read();
    outgoing = (char) incoming;
    Serial.write(outgoing);
  } else {
    if (lastAvailable){
      lastAvailable = 0;
      Serial.println("");
      Serial.flush();
      digitalWrite(led, LOW);
    }
  }
}
