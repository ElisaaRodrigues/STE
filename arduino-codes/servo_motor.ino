//classe para tratar servo motor
//utilizado Tinkercad para teste
#include <Servo.h> // use Arduino Servo library
Servo servomotor; 
int analogPin = A0;

void setup() {
 Serial.begin(9600);
servomotor.attach(3);

pinMode(3, OUTPUT); 
}

void loop() {
  
  int input = analogRead(analogPin);
  analogWrite(11, input/4);
  int angle = (((input/4)*180)/255);
  servomotor.write(angle);
  Serial.print("valor pwm: ");
  Serial.println(input/4);
  Serial.print("valor angle: ");
  Serial.println(angle);

  delay(1000);
}
