/*
 * Digital I/O:
 * 
 *    Quando ambos botões pressionados o LED deve acender.
 *    > pinos 8 (PB0) e 9 (PB1) como entrada (BOTOES)
 *    > pino 13 (PB5) como saida (LED)
 *    > implementação sem utilizar as bibliotecas do Arduino
 *    
 *    DDRB – The Port B Data Direction Register
 *    > input (0) or output (1)
 * 
 *    PORTB – The Port B Data Register
 *    > write bits
 * 
 *    PINB – The Port B Input Pins Address
 *    > read bits
*/

//#include <avr/io.h>
//#include <Arduino.h>

volatile byte *ddrb = (byte *) 0x24;
volatile byte *portb = (byte *) 0x25;
volatile byte *pinb = (byte *) 0x23;

const byte PIN_13 = 0x20;
const byte PIN_8_9 = 0x03;

void setup() {

  //  DDRB = xx1x xx00
  // para setar '1' : DDRB = DDRB | 0010 0000 (0x20)
  // para setar '0' : DDRB = DDRB & 1111 1100 (0XFC == ~0x03)

  *ddrb |= PIN_13;
  *ddrb &= ~PIN_8_9;

  Serial.begin(9600);
  
}

void loop() {
  //verifica se ambos botoes pressionados, se sim acende led

  byte result = *pinb & PIN_8_9;
  if(result == PIN_8_9){
    //Serial.print("acende\n");
    *portb |= PIN_13;
  }else{
    //Serial.print("apaga\n");
    *portb &= ~PIN_13;
  }

}
