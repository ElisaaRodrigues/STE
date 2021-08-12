//conversor ADC do avr
#include <avr/io.h>

const byte channel = 0x00; //define o canal
const byte divisor = 0x03; //define o fator de divisao
const byte mask1 = 0x10; //para verificar de ADIF esta aceso e tem dado para ler
const byte mask2 = 0x40; //para acender ADSC e iniciar conversao

void setup() {
  
  //bits e canal:
  ADMUX = channel; //0x00 entrada analogica 0
  ADCSRA = 0x88 | divisor;
  ADCSRB = 0x00; //irá fazer a leitura livre, sem necessidade de um trigger para ativa-la: Free running mode
  Serial.begin(9600);

}

void loop() {
  
  if ((ADCSRA & mask1)!= 0){
    unsigned short dado = (ADCH  << 8) | ADCL;
    Serial.println(dado);
   
  }else{
    ADCSRA |= mask2;
  }
  
}
