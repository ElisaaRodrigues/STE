#define LDR_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int ldr = analogRead(LDR_PIN);
  Serial.print("LDR_PIN: ");
  Serial.println(ldr);
  delay(500);
}
