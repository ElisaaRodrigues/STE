//medindo temperatura com TPM36
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(EXTERNAL);
  
}


void loop() {
  float d = analogRead(A0); // sample ADC output
  float v = 3.3 * d / 1024.; 
  float temp;
  
  if (v < 0.1)
  temp = -40.;
  else if (v < 1.75)
  temp = ((100.*v)-50.);
  else temp = 125.;
  
  Serial.print(temp);
  Serial.println(" graus Celsius");
  
  float tf;
  
  tf = ((temp*9./5.)+32.);
  
  Serial.print(tf);
  Serial.println(" graus Fahrenheit");
  delay(2000); // wait 1s
}
