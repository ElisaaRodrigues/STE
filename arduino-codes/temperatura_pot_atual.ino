int analogPin = A0;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int tensao_bit = analogRead(analogPin);
  Serial.print("Tensao_bit: ");
  Serial.println(tensao_bit);
  float tensao = (tensao_bit*4)/1023;

  Serial.print("Tensao: ");
  Serial.println(tensao);
  delay(1000);
}
