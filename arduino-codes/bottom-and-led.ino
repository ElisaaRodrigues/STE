//
//int state = 0;
//
//void setup() {
//  pinMode(13, OUTPUT);
//}
//void loop() {
//  if (state == 0) {
//  state = 1;
//  digitalWrite(13, HIGH); // LED on
//  } else /* state == 1 */ {
//  state = 0;
//  digitalWrite(13, LOW); // LED off
//  }
//  delay(1000); // wait 1000ms = 1s
//}

//void setup() {
//  pinMode(2, INPUT);
//  Serial.begin(9600); // open serial port to host
// }
//void loop() {
//  int v = digitalRead(2); // sense voltage at pin 2
//  Serial.println(v); // send voltage to host
//  delay(1000); // wait 100ms
//}


volatile byte state = LOW; // initially button not pushed

void setup() {
  pinMode(2, INPUT); // interrupt (sensor) pin
  pinMode(13, OUTPUT); // LED (actuator) pin
  attachInterrupt(digitalPinToInterrupt(2),
  handleButton, CHANGE);
}
void loop() {
  digitalWrite(13, state);
  delay(10);
  }
  /****** interrupt handler ******/
  
void handleButton() {
  state = !state;
  Serial.println(state);
} 
