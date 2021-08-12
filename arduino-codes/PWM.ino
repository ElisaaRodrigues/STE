

int analogPin = A0;
int tensao_bit = 0;


void setup() { 
  Serial.begin(9600);
  pinMode(11, OUTPUT); //pino do led
}

void loop() {
  
  int tensao_bit = analogRead(analogPin);
  Serial.println(tensao_bit >> 2);
  analogWrite(11, tensao_bit/4);
  

  delay(10);
}
