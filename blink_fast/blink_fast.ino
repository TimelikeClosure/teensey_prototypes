// Simple LED blink

const int led = LED_BUILTIN;
unsigned int count = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(300);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(300);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(2000);
  count++;
//  Serial.print("The blink has blunk ");
//  Serial.print(count);
//  Serial.println(" times!");
}
