
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  byte A = B01000001;
  byte B = B01000010;
  byte r_and = A&B;
  byte r_or = A|B;
  byte r_xor = A^B;
  byte r_com = ~A;

  Serial.print("resultado operação AND: ");
  Serial.println(r_and);
  Serial.print("resultado operação OR: ");
  Serial.println(r_or);
  Serial.print("resultado operação XOR: ");
  Serial.println(r_xor);
  Serial.print("resultado operação COMPLEMENT: ");
  Serial.println(r_com);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  

}
