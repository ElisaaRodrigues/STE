#include <avr/io.h>

const byte I_Bit = 0x80; //I-bit SREG
const byte WGM_13 = 0x00; //wgm13 para normal mode
const byte TOV_1 = 0x01; //sinalizador do estouro do timer
const byte TOIE_1 = 0x01; // habilita a interrupção por estouro do timer
const byte mask1 = 0x01; //para acender TOV1 

void setup() {
  
  SREG = I_Bit; //habilitar o I-bit do SREG
  TCCR1B = WGM_13; //modo normal WGM13=0
  TIFR1 = TOV_1;
  TIMSK1 = TOIE_1;
  
  Serial.begin(9600);

}

void loop() {
  
  if ((TIFR1 & mask1)== 0){
    Serial.println("Ocorreu estouro do timer");
    TIFR1 = TOV_1;
   
  }
  
}
